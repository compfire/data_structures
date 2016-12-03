//
// Created by danza on 3.12.2016.
//

#include <bits/stdc++.h>
#include "UnionFindDisjointSets.h"

using namespace std;

UnionFindDisjointSets::UnionFindDisjointSets(int N) {
    p.assign(N, 0);
    rank.assign(N, 0);
    for(int i = 0; i < N; i++) p[i] = i;
}

int UnionFindDisjointSets::find_set(int x) {
    return p[x] == x ? x : (p[x] = find_set(p[x]));
}

bool UnionFindDisjointSets::is_same_set(int a, int b) {
    return (find_set(a) == find_set(b));
}

void UnionFindDisjointSets::union_set(int a, int b) {
    if(!is_same_set(a, b)) {
        int x = find_set(a), y = find_set(b);
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
}