//
// Created by danza on 22.9.2016.
//

#ifndef COMPLOOK_HEAP_H
#define COMPLOOK_HEAP_H

#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

public:
    Heap();
    vector<int> add_element(int to_add);
    void print_heap();
    void remove_max();
    int get_max();
};


#endif //COMPLOOK_HEAP_H
