#include "include/mergesortfuncs.h"
#include "include/gmthreadpool.h"
#include "include/gmmergesorttask.h"
#include <math.h>
#include <algorithm>

using namespace std;
vector<int> merge(vector<int> &vec,const vector<int>& left, const vector<int>& right)
{
    vector<int> result;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size())
    {
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    vec = result;
    return vec;
}

vector<int> merge_sort(vector<int>& vec)
{

    if(vec.size() == 1)
        return vec;

    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(vec,left, right);
}

vector<int> merge_sort_multithreaded(vector<int>& vec, size_t height, gmThreadPool* pool)
{

    if(vec.size() == 1)
        return vec;

    gmMergeSortTask* sortTask = new gmMergeSortTask(vec, log2(height), pool);
    pool->SubmitTask(sortTask);
    sortTask->Result();

    return vec;
}

