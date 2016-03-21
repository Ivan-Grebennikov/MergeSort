#include <iostream>
#include <vector>
#include <wx/init.h>
#include <wx/time.h>
#include <include/gmthreadpool.h>
#include <include/gmmergesorttask.h>
#include <include/mergesortfuncs.h>

#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/textfile.h>
#include <wx/stopwatch.h>

#define ARRAY_SIZE 1000000
#define THREADS_NUM

void IsSorted(const std::vector<int>& v) {
    std::vector<int>::const_iterator it = v.begin();
    for(; it!= v.end() - 1 ; ++it) {
        if ((*it) > *(it + 1))
            throw std::exception();
    }
}

int main(){

    wxInitialize();

    std::cout << "Generate random array of " << ARRAY_SIZE << " elements" << std::endl;

    std::vector<int> v;
    srand(wxGetLocalTime());
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
        v.push_back(rand() % 1000);

    std::cout << "Write unsorted array to file... " << std::endl;

    {
        wxTextFile file("input_array");
        if (file.IsOpened()) {
            file.Clear();
            file.Close();
        }
        wxFileOutputStream fileStream("input_array");
        wxTextOutputStream textStream(fileStream);

        textStream << "Input Array" <<  wxTextFile::GetEOL();
        for (size_t i = 0; i < v.size(); ++i) {
            if (i % 20 == 0)
                textStream << wxTextFile::GetEOL();
            textStream << v.at(i) << " ";
        }
    }


    std::cout << "Start simple sort..." << std::endl;
    std::vector<int> tmp = v;
    {
        wxStopWatch chrono;
        chrono.Start();
        merge_sort(tmp);
        IsSorted(tmp);
        chrono.Pause();
        std::cout << "Simple sort finised! Elapsed time: " << chrono.Time() << std::endl;
    }

    gmThreadPool* pool = new gmThreadPool;

    std::cout << "Start multithreading sort..." << std::endl;
    {
        wxStopWatch chrono;
        chrono.Start();
        merge_sort_multithreaded(v, pool->GetThreadsCount(), pool);
        IsSorted(v);
        chrono.Pause();
        std::cout << "Multithreading sort finised! Elapsed time: " << chrono.Time() << std::endl;
    }

    std::cout << "Write sorted array to file... " << std::endl;

    {
        wxTextFile file("sorted_array");
        if (file.IsOpened()) {
            file.Clear();
            file.Close();
        }
        wxFileOutputStream fileStream("sorted_array");
        wxTextOutputStream textStream(fileStream);

        textStream << "Sorted Array" <<  wxTextFile::GetEOL();
        for (size_t i = 0; i < v.size(); ++i) {
            if (i % 20 == 0)
                textStream << wxTextFile::GetEOL();
            textStream << v.at(i) << " ";
        }
    }


    delete pool;

    wxUninitialize();
    return 0;
}
