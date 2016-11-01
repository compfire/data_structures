#include <iostream>
#include <vector>

#include "GraphTraversal.h"

using namespace std;


int main() {
    GraphTraversal gt;
    vector<vector<pair<int, int>>> graph(8);
    int t, v, c;
    for(int i = 0; i < 14; i++) {
        cin >> t >> v >> c;
        graph[t].push_back(make_pair(v, c));
    }

    cout << gt.dijkstra_shortest_path_length(graph, 0, 6) << endl;


    return 0;
}