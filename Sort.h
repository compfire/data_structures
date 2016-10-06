//
// Created by danza on 5.10.2016.
//

#ifndef COMPLOOK_SORT_H
#define COMPLOOK_SORT_H

#include <vector>

using namespace std;


class Sort {
private:
    vector<int> merge_to;
public:
    void bubble_sort(vector<int> &to_sort);
    void selection_sort(vector<int> &to_sort);
    void insertion_sort(vector<int> &to_sort);
    void quick_sort(vector<int> &to_sort, int start, int end);
    int partition(vector<int> &to_sort, int start, int end);
    void merge_sort(vector<int> &to_sort, int start, int end);
    void merge(vector<int> &merge_from, int start, int mid, int end);
};


#endif //COMPLOOK_SORT_H
