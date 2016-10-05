//
// Created by danza on 5.10.2016.
//

#include "Sort.h"
#include <vector>
#include <limits>

void Sort::bubble_sort(vector<int> &to_sort) {
    for(int i = 0; i < to_sort.size(); i++) {
        for(int j = 0; j < to_sort.size() - 1; j++) {
            if(to_sort[j] > to_sort[j + 1])
                swap(to_sort[j], to_sort[j + 1]);
        }
    }
}

void Sort::selection_sort(vector<int> &to_sort) {
    int min, min_val;
    for(int i = 0; i < to_sort.size(); i++) {
        min_val = numeric_limits<int>::max();
        for(int j = i; j < to_sort.size(); j++) {
            if(to_sort[j] < min_val) {
                min_val = to_sort[j];
                min = j;
            }
        }
        swap(to_sort[i], to_sort[min]);
    }
}

void Sort::insertion_sort(vector<int> &to_sort) {
    int act_index;
    for(int i = 1; i < to_sort.size(); i++) {
        act_index = i;
        while(act_index > 0 && to_sort[act_index] < to_sort[--act_index]) {
            swap(to_sort[act_index + 1], to_sort[act_index]);
        }
    }
}

void Sort::quick_sort(vector<int> &to_sort, int start, int end) {
    if(start < end) {
        int p_index = partition(to_sort, start, end);
        quick_sort(to_sort, start, p_index - 1);
        quick_sort(to_sort, p_index + 1, end);
    }
}

int Sort::partition(vector<int> &to_sort, int start, int end) {
    int pivot = to_sort[end];
    int p_index = start;
    for(int i = start; i <= end; i++) {
        if(to_sort[i] < pivot) {
            swap(to_sort[i], to_sort[p_index]);
            p_index++;
        }
    }
    swap(to_sort[end], to_sort[p_index]);
    return p_index;
}


























