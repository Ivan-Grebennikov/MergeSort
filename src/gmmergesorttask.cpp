#include "include/gmmergesorttask.h"
#include "include/gmthreadpool.h"
#include "include/mergesortfuncs.h"
#include <algorithm>

gmMergeSortTask::gmMergeSortTask(std::vector<int> &v, size_t height, gmThreadPool* pool):
    mContainer(v),
    mHeight(height),
    mPool(pool)
{}

gmTask::gmTASK_TYPE gmMergeSortTask::Type() const
{
    return gmTASK_MERGESORT;
}

int gmMergeSortTask::Run()
{
    if(mContainer.size() == 1)
        return 0;

    if(mHeight == 1) {
        sort(mContainer.begin(), mContainer.end());
        return 0;
    }

    mHeight--;
    std::vector<int>::iterator middle = mContainer.begin() + (mContainer.size() / 2);
    std::vector<int> left(mContainer.begin(), middle);
    std::vector<int> right(middle, mContainer.end());

    gmMergeSortTask* leftSortTask = new gmMergeSortTask(left, mHeight, mPool);
    gmMergeSortTask* rightSortTask = new gmMergeSortTask(right, mHeight, mPool);

    mPool->SubmitTask(leftSortTask);
    mPool->SubmitTask(rightSortTask);

    leftSortTask->Result();
    rightSortTask->Result();

    merge(mContainer, left, right);
    return 0;
}
