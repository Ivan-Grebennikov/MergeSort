#ifndef MERGESORTFUNCS_H
#define MERGESORTFUNCS_H

#include <vector>
#include <stddef.h>

class gmThreadPool;

std::vector<int> merge(std::vector<int> &vec,const std::vector<int>& left, const std::vector<int>& right);
std::vector<int> merge_sort(std::vector<int>& vec);
std::vector<int> merge_sort_multithreaded(std::vector<int>& vec, size_t height, gmThreadPool* pool);


#endif // MERGESORTFUNCS_H
