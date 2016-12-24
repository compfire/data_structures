#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

typedef vector<int> vi;

int main() {
    vi vec = {1, 2, 3, 4, 5, 6};
    SegmentTree t(vec);
    for(int i = 0; i < t.st.size(); i++) cout << t.st[i] << " ";
    cout << endl << t.rmq(3, 5) << endl;
    t.update(3, -100);
    cout << t.rmq(0, 5) << endl;

    return 0;
}