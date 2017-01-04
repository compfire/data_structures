#include <bits/stdc++.h>
#include "GraphTraversal.h"

using namespace std;

typedef vector<int> vi;

int main() {
    vector<vi> G = {
            {},
            {0, 3},
            {0, 3},
            {1, 2},
    };

    GraphTraversal gt(4);
    cout << gt.dfs_reachable(G, 0, 3) << endl;

    return 0;
}