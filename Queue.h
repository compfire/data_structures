//
// Created by danza on 28.9.2016.
//

#ifndef COMPLOOK_QUEUE_H
#define COMPLOOK_QUEUE_H

#include <vector>

using namespace std;

class Queue {
private:
    vector<int> elements;
public:
    void add(int element);
    int get();
    int pull();
    void print_queue();
};


#endif //COMPLOOK_QUEUE_H
