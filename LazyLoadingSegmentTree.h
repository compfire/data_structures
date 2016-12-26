//
// Created by danza on 25.12.2016.
//

#ifndef COMPLOOK_LAZYLOADINGSEGMENTTREE_H
#define COMPLOOK_LAZYLOADINGSEGMENTTREE_H
#include <bits/stdc++.h>

using namespace std;

class LazyLoadingSegmentTree {
    vector<int> st, A, lz;
    int n;
    int left(int p);
    int right(int p);
    int build(int p, int L, int R);
    int rmq(int p, int L, int R, int i, int j);
    int update(int p, int L, int R, int i, int j, int val);
public:
    LazyLoadingSegmentTree(vector<int> &_A);
    int rmq(int i, int j);
    int update(int i, int j, int val);
};


#endif //COMPLOOK_LAZYLOADINGSEGMENTTREE_H
