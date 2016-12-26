//
// Created by danza on 25.12.2016.
//

#include "LazyLoadingSegmentTree.h"

LazyLoadingSegmentTree::LazyLoadingSegmentTree(vector<int> &_A) {
    A = _A;
    n = A.size();
    st.assign(4 * n, 0);
    lz.assign(4 * n, 0);
    build(1, 0, n - 1);
}

int LazyLoadingSegmentTree::left(int p) { return p << 1; }
int LazyLoadingSegmentTree::right(int p) { return p << 1 | 1; }

int LazyLoadingSegmentTree::build(int p, int L, int R) {
    if(L == R) return st[p] = A[L];
    build(left(p), L, (L + R) >> 1);
    build(right(p), ((L + R) >> 1) + 1, R);
    return st[p] = max(st[left(p)], st[right(p)]);
}

int LazyLoadingSegmentTree::rmq(int p, int L, int R, int i, int j) {
    if(j < L || i > R) return 0;
    if(i <= L && j >= R) return st[p] + lz[p];
    if(lz[p] != 0) {
        st[p] += lz[p];
        lz[left(p)] += lz[p];
        lz[right(p)] += lz[p];
        lz[p] = 0;
    }
    int p1 = rmq(left(p), L, (L + R) >> 1, i, j);
    int p2 = rmq(right(p), ((L + R) >> 1) + 1, R, i, j);
    return max(p1, p2);
}

int LazyLoadingSegmentTree::update(int p, int L, int R, int i, int j, int val) {
    if(j < L || i > R) return st[p] + lz[p];
    if(L >= i && R <= j) {
        if(L == R) {
            st[p] += lz[p] + val;
            lz[p] = 0;
            return st[p];
        }
        lz[p] += val;
        return st[p] + lz[p];
    }
    st[p] += lz[p];
    lz[left(p)] += lz[p];
    lz[right(p)] += lz[p];
    lz[p] = 0;
    int p1 = update(left(p), L, (L + R) >> 1, i, j, val);
    int p2 = update(right(p), ((L + R) >> 1) + 1, R, i, j, val);
    return st[p] = max(p1, p2);
}

int LazyLoadingSegmentTree::rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
int LazyLoadingSegmentTree::update(int i, int j, int val) { return update(1, 0, n - 1, i, j, val); }