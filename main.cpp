#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

typedef vector<int> vi;

int main() {
    vi arr = {9, 2, 3, 4, 2};
    SegmentTree st(arr);
    cout << st.rmq(0, 4) << endl;
    cout << st.rmq(3, 3) << endl;
    cout << st.rmq(3, 4) << endl;
    st.update(0, -100);
    cout << st.rmq(0, 4) << endl;
    st.update(0, 100);
    cout << st.rmq(0, 4) << endl;
    st.update(0, -100);
    cout << st.rmq(0, 4) << endl;
    st.update(0, 100);
    cout << st.rmq(0, 4) << endl;
    return 0;
}