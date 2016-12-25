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

void LazyLoadingSegmentTree::build(int p, int L, int R) {
    if(L == R) st[p] = A[L];
    else {
        build(left(p), L, (L + R) >> 1);
        build(right(p), ((L + R) >> 1) + 1, R);
        st[p] = max(st[left(p)], st[right(p)]);
    }
}

int LazyLoadingSegmentTree::rmq(int p, int L, int R, int i, int j) {
    if(j < L || i > R) return -1;
    if(i <= L && j >= R) {
        st[p] += lz[p];
        if(L != R) {
            lz[left(p)] += lz[p];
            lz[right(p)] += lz[p];
        }
        lz[p] = 0;
        return st[p];
    }
    int p1 = rmq(left(p), L, (L + R) >> 1, i, j);
    int p2 = rmq(right(p), ((L + R) >> 1) + 1, R, i, j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return max(p1, p2);
}

int LazyLoadingSegmentTree::update(int p, int L, int R, int i, int j, int val) {
    if(j < L || i > R) return -1;
    if(L >= i && R <= j) {
        st[p] += lz[p] + val;
        if(L != R) {
            lz[left(p)] += lz[p] + val;
            lz[right(p)] += lz[p] + val;
        }
        lz[p] = 0;
        return st[p];
    }
    int p1 = update(left(p), L, (L + R) >> 1, i, j, val);
    int p2 = update(right(p), ((L + R) >> 1) + 1, R, i, j, val);
    return st[p] = max(p1, p2);
}

int LazyLoadingSegmentTree::rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
int LazyLoadingSegmentTree::update(int i, int j, int val) { return update(1, 0, n - 1, i, j, val); }

















































