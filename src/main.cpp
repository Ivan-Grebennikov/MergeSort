#include <iostream>
#include <vector>
#include <wx/init.h>
#include <wx/time.h>
#include <include/gmthreadpool.h>
#include <include/gmmergesorttask.h>
#include <include/mergesortfuncs.h>

#define ARRAY_SIZE 1000000
#define THREADS_NUM

int main(){

    wxInitialize();

    std::cout << "Generate random array of " << ARRAY_SIZE << " elements" << std::endl;

    std::vector<int> v;
    srand(wxGetLocalTime());
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
        v.push_back(rand() % 1000);

    gmThreadPool* pool = new gmThreadPool;
    std::cout << "Start multithreading sort..." << std::endl;
    merge_sort_multithreaded(v, pool->GetThreadsCount(), pool);
    std::cout << "Finised!" << std::endl;

    delete pool;

    wxUninitialize();
    return 0;
}
