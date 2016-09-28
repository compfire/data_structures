//
// Created by danza on 28.9.2016.
//

#include <iostream>
#include <vector>
#include <limits>
#include "Queue.h"

using namespace std;

void Queue::add(int element) {
    elements.push_back(element);
}

int Queue::get() {
    if(elements.empty())
        return numeric_limits<int>::min();
    return elements[0];
}

int Queue::pull() {
    if(!elements.empty()) {
        int first_element = elements[0];
        elements.erase(elements.begin());
        return first_element;
    }
}

void Queue::print_queue() {
    for(int i = 0; i < elements.size(); i++)
        cout << elements[i] << " : ";
}
