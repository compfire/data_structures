//
// Created by danza on 5.10.2016.
//

#ifndef COMPLOOK_SORT_H
#define COMPLOOK_SORT_H

#include <vector>

using namespace std;


class Sort {
public:
    void bubble_sort(vector<int> &to_sort);
    void selection_sort(vector<int> &to_sort);
    void insertion_sort(vector<int> &to_sort);
    void quick_sort(vector<int> &to_sort, int start, int end);
    int partition(vector<int> &to_sort, int start, int end);
};


#endif //COMPLOOK_SORT_H
