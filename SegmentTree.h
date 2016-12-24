//
// Created by danza on 4.12.2016.
//

#ifndef COMPLOOK_SEGMENTTREE_H
#define COMPLOOK_SEGMENTTREE_H

#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
public:
    vector<int> st, A;
    int n;
    int left(int p);
    int right(int p);
    void build(int p, int L, int R);
    int rmq(int p, int L, int R, int i, int j);
    int update(int p, int L, int R, int i, int val);
    SegmentTree(const vector<int> &_A);
    int rmq(int i, int j);
    int update(int i, int val);
};


#endif //COMPLOOK_SEGMENTTREE_H
