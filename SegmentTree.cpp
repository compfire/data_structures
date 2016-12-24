//
// Created by danza on 4.12.2016.
//

#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

SegmentTree::SegmentTree(const vector<int> &_A) {
    A = _A;
    n = A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
}
int SegmentTree::left(int p) { return (p << 1); }
int SegmentTree::right(int p) { return (p << 1) + 1; }
void SegmentTree::build(int p, int L, int R) {
    if(L == R) st[p] = A[L];
    else {
        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R) / 2 + 1, R);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = p1 <= p2 ? p1 : p2;
    }
}
int SegmentTree::rmq(int p, int L, int R, int i, int j) {
    if(i > R || j < L) return -1;
    if(L >= i && R <= j) return st[p];
    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return p1 <= p2 ? p1 : p2;
}

//In progress
int SegmentTree::update(int p, int L, int R, int i, int val) {
    if(i > R || i < L) return -1;
    if(L == i && R == i) {
        A[L] += val;
        return st[p] = A[L];
    }
    int p1 = update(left(p), L, (L + R) / 2, i, val);
    int p2 = update(right(p), (L + R) / 2 + 1, R, i, val);
    return st[p] = p1 <= p2 ? p1 : p2;
}

int SegmentTree::update(int i, int val) { return update(1, 0, n - 1, i, val); }
int SegmentTree::rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }