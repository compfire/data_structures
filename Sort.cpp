//
// Created by danza on 5.10.2016.
//

#include "Sort.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


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

void Sort::merge_sort(vector<int> &to_sort, int start, int end) {
    if(end - start < 2)
        return;
    int mid = (start + end) / 2;
    merge_sort(to_sort, start, mid);
    merge_sort(to_sort, mid, end);
    merge(to_sort, start, mid, end);
}

void Sort::merge(vector<int> &merge_from, int start, int mid, int end) {
    int left_index = start, right_index = mid;
    temp_vec.clear();
    while(left_index < mid && right_index < end) {
        if(merge_from[left_index] < merge_from[right_index])
            temp_vec.push_back(merge_from[left_index++]);
        else
            temp_vec.push_back(merge_from[right_index++]);
    }
    while(left_index < mid)
        temp_vec.push_back(merge_from[left_index++]);
    while(right_index < end)
        temp_vec.push_back(merge_from[right_index++]);
    for(int i = start; i < end; i++)
        merge_from[i] = temp_vec[i - start];
}

void Sort::counting_sort(vector<int> &to_sort) {
    int max_num = numeric_limits<int>::min();
    for(int i = 0; i < to_sort.size(); i++)
        if(to_sort[i] > max_num)
            max_num = to_sort[i];
    int amounts[max_num + 1];
    for(int i = 0; i <= max_num; i++)
        amounts[i] = 0;
    for(int i = 0; i < to_sort.size(); i++)
        amounts[to_sort[i]]++;
    to_sort.clear();
    for(int i = 0; i <= max_num; i++) {
        while(amounts[i] > 0) {
            to_sort.push_back(i);
            amounts[i]--;
        }
    }
}

void Sort::counting_sort2(vector<int> &to_sort) {
    int max_num = numeric_limits<int>::min();
    for(int i = 0; i < to_sort.size(); i++)
        if(to_sort[i] > max_num)
            max_num = to_sort[i];
    int indexes[max_num + 1];
    for(int i = 0; i <= max_num; i++)
        indexes[i] = 0;
    cout << endl;
    for(int i = 0; i < to_sort.size(); i++)
        indexes[to_sort[i]]++;
    for(int i = 1; i <= max_num; i++)
        indexes[i] += indexes[i - 1];
    int sorted[to_sort.size()];
    for(int i = to_sort.size() - 1; i >= 0; i--)
        sorted[--indexes[to_sort[i]]] = to_sort[i];
    for(int i = 0; i < to_sort.size(); i++)
        to_sort[i] = sorted[i];
}

void Sort::radix_sort(vector<int> &to_sort) {
    bool finished = false;
    int modulus_number = 1;
    int radix[10];
    int result[to_sort.size()];
    while(!finished) {
        modulus_number *= 10;
        finished = true;
        for (int i = 0; i < 10; i++)
            radix[i] = 0;
        for (int i = 0; i < to_sort.size(); i++) {
            if(to_sort[i] < modulus_number / 10 && to_sort[i] > 9)
                radix[0]++;
            else
                radix[(to_sort[i] / (modulus_number / 10)) % modulus_number]++;
        }
        for (int i = 1; i < 10; i++)
            radix[i] += radix[i - 1];
        for (int i = to_sort.size() - 1; i >= 0; i--)
            result[--radix[(to_sort[i] / (modulus_number / 10)) % modulus_number]] = to_sort[i];
        for (int i = 0; i < to_sort.size(); i++) {
            to_sort[i] = result[i];
            if (to_sort[i] >= modulus_number)
                finished = false;
        }
    }
}

























