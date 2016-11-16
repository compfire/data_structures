#include <iostream>
#include <vector>
#include <ctime>
#include "FenwickTree.h"

using namespace std;


int main() {
    FenwickTree fentree;
    int n, t;
    cin >> n;
    vector<int> nums, fenvec((unsigned)n + 1);
    for(int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }

    for(int i = 1; i <= n; i++)
        fentree.insert(fenvec, nums, i);

    cout << fentree.sum(fenvec, 0, n - 1) << endl;
    fentree.update(fenvec, 0, 1);
    cout << fentree.sum(fenvec, 0, n - 1) << endl;


    return 0;
}