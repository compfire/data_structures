//
// Created by danza on 22.9.2016.
//
#include "Heap.h"

Heap::Heap() {
    heap.resize(1);
}

vector<int> Heap::add_element(int to_add) {
    heap.push_back(to_add);
    int cur_index = heap.size() - 1;
    while(cur_index > 1) {
        cout << cur_index << endl;
        if(heap[cur_index] > heap[cur_index/2]) {
            swap(heap[cur_index], heap[cur_index / 2]);
            cur_index /= 2;
        }
        else
            break;
    }
    return heap;
}

void Heap::print_heap() {
        for(int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ; ";
        cout << endl;
}

void Heap::remove_max() {
    if(heap.size() < 2)
        return;
    swap(heap[1], heap[heap.size()-1]);
    heap.pop_back();
    int cur_index = 1;
    while(cur_index * 2 < heap.size()) {
        if(heap[cur_index] < heap[cur_index * 2]) {
            if (heap[cur_index * 2] < heap[cur_index * 2 + 1] && cur_index * 2 + 1 < heap.size()) {
                swap(heap[cur_index], heap[cur_index * 2 + 1]);
                cur_index = cur_index * 2 + 1;
            } else {
                swap(heap[cur_index], heap[cur_index * 2]);
                cur_index *= 2;
            }
        }
        else
            break;
    }
}

int Heap::get_max() {
    try {
        if(heap.size() < 2)
            throw("Heap empty");
    }
    catch(...) {
        cout << "Heap empty" << endl;
        return -1;
    }
    return heap[1];
}















