//
// Created by danza on 16.11.2016.
//

#include<vector>
#include <iostream>

#ifndef COMPLOOK_FENWICKTREE_H
#define COMPLOOK_FENWICKTREE_H

using namespace std;

class FenwickTree {
public:
    void insert(vector<int> &fenwick_tree, vector<int> &input_vector, int index);
    int sum_from_start(vector<int> &fenwick_tree, int to);
    int sum(vector<int> &fenwick_tree, int from, int to);
    void update(vector<int> &fenwick_tree, int position, int value);
};


#endif //COMPLOOK_FENWICKTREE_H
