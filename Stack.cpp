//
// Created by danza on 28.9.2016.
//

#include <iostream>
#include <vector>
#include <limits>
#include "Stack.h"

using namespace std;


void Stack::add(int element) {
    elements.push_back(element);
}

int Stack::get() {
    if(elements.empty())
        return numeric_limits<int>::min();
    return elements[elements.size() - 1];
}

int Stack::pop() {
    if(elements.empty())
        return numeric_limits<int>::min();
    int last_element = elements[elements.size() - 1];
    elements.pop_back();
    return last_element;
}

void Stack::print_stack() {
    for(int i = 0; i < elements.size(); i++)
        cout << elements[i] << " : ";
}