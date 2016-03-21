#ifndef GMMERGESORTTASK_H
#define GMMERGESORTTASK_H


#include "gmtask.h"
#include <vector>

class gmThreadPool;

class gmMergeSortTask : public gmTask
{
public:
    gmMergeSortTask(std::vector<int>& v, size_t height, gmThreadPool* pool);

    gmTASK_TYPE Type() const;

protected:
    virtual int Run();

private:
    std::vector<int> &mContainer;
    size_t mHeight;
    gmThreadPool* mPool;
};

#endif // GMMERGESORTTASK_H
