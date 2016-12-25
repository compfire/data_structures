#include <bits/stdc++.h>
#include "LazyLoadingSegmentTree.h"

using namespace std;

typedef vector<int> vi;

int main() {
    vi vec = {1, 2, 3, 4, 5, 6};
    LazyLoadingSegmentTree t(vec);
    cout << t.rmq(3, 5) << endl;
    t.update(0, 2, 100);
    cout << t.rmq(0, 5);

    return 0;
}