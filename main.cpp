#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

typedef vector<int> vi;

int main() {
    int arr[] = {18, 17, 13, 19, 15, 11, 20};
    vi A(arr, arr + 7);
    SegmentTree st(A);
    cout << "RMQ(1, 3) = " << st.rmq(1, 3) << endl;
    cout << "RMQ(4, 6) = " << st.rmq(4, 6) << endl;

    return 0;
}