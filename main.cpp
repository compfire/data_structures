#include <bits/stdc++.h>
#include "UnionFindDisjointSets.h"

using namespace std;

int main() {
    UnionFindDisjointSets ufds(10);
    ufds.union_set(1, 2);
    ufds.union_set(1, 0);
    cout << ufds.is_same_set(0, 1) << endl;
    cout << ufds.is_same_set(0, 2) << endl;
    cout << ufds.is_same_set(1, 2) << endl;
    cout << ufds.is_same_set(1, 5) << endl;


    return 0;
}