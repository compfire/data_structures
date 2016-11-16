//
// Created by danza on 16.11.2016.
//

#include "FenwickTree.h"
#include <iostream>
#include <vector>


void FenwickTree::insert(vector<int> &fenwick_tree, vector<int> &input_vector, int index) {
    int sum = 0;
    for(int i = index - (index & -index); i < index; i++)
        sum += input_vector[i];
    fenwick_tree[index] = sum;
}

int FenwickTree::sum_from_start(vector<int> &fenwick_tree, int to) {
    to++;
    int res = 0;
    while(to > 0) {
        res += fenwick_tree[to];
        to -= (to & -to);
    }
    return res;
}

int FenwickTree::sum(vector<int> &fenwick_tree, int from, int to) {
    return sum_from_start(fenwick_tree, to) - sum_from_start(fenwick_tree, from - 1);
}

void FenwickTree::update(vector<int> &fenwick_tree, int position, int value) {
    position++;
    while(position < fenwick_tree.size()) {
        fenwick_tree[position] += value;
        position += (position & -position);
    }
}