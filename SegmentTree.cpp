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
    int nulls = 0, stnulls = 0;
    for(int i = A.size() - 1; i > 0; i--) {
        if(A[i] == 0) nulls++;
        else break;
    }
    for(int i = st.size(); i > 0; i--) {
        if(st[i] == 0) stnulls++;
        else break;
    }
    stnulls -= nulls;
    end = stnulls - 1;
    if(!((A.size() - 1) - ((A.size() - 1) & -(A.size() - 1)))) end++;
    int msb = end;
    while(msb - (msb & -msb)) msb -= (msb & -msb);
    start = msb;
}
int SegmentTree::left(int p) { return (p << 1); }
int SegmentTree::right(int p) { return (p << 1) + 1; }
void SegmentTree::build(int p, int L, int R) {
    if(L == R) st[p] = L;
    else {
        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R) / 2 + 1, R);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = A[p1] <= A[p2] ? p1 : p2;
    }
}
int SegmentTree::rmq(int p, int L, int R, int i, int j) {
    if(i > R || j < L) return -1;
    if(L >= i && R <= j) return st[p];
    int p1 = rmq(left(p), L, (L + R) / 2, i, j), p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return A[p1] <= A[p2] ? p1 : p2;
}

void SegmentTree::update(int pos, int val) {
    A[pos] += val;
    int a;
    if(end - start < pos) {
        pos -= (end - start);
        a = start - 1 - (A.size() - (end - start)) + pos;
    }
    else a = start + pos;
    while(a > 1) {
        if(a % 2 == 0) {
            if(a + 1 >= st.size()) st[a / 2] = st[a];
            else st[a / 2] = A[st[a]] <= A[st[a + 1]] ? st[a] : st[a + 1];
        }
        else st[a / 2] = A[st[a]] <= A[st[a - 1]] ? st[a] : st[a - 1];
        a /= 2;
    }
}

int SegmentTree::rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
