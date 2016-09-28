//
// Created by danza on 28.9.2016.
//

#ifndef COMPLOOK_STACK_H
#define COMPLOOK_STACK_H

#include <vector>

using namespace std;


class Stack {
private:
    vector<int> elements;
public:
    void add(int element);
    int get();
    int pop();
    void print_stack();
};


#endif //COMPLOOK_STACK_H
