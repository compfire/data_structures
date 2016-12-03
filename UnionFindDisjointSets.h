//
// Created by danza on 3.12.2016.
//

#ifndef COMPLOOK_UNIONFINDDISJOINTSETS_H
#define COMPLOOK_UNIONFINDDISJOINTSETS_H

#include <bits/stdc++.h>

using namespace std;

class UnionFindDisjointSets {
private:
    vector<int> p, rank;
public:
    UnionFindDisjointSets(int N);
    int find_set(int x);
    bool is_same_set(int a, int b);
    void union_set(int a, int b);
};


#endif //COMPLOOK_UNIONFINDDISJOINTSETS_H
