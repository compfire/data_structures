//
// Created by danza on 26.10.2016.
//

#ifndef COMPLOOK_GRAPHTRAVERSAL_H
#define COMPLOOK_GRAPHTRAVERSAL_H

#include <vector>
#include <queue>

using namespace std;

class GraphTraversal {
private:
    struct Node {
        int value;
        vector<pair<int, int>> paths;
        bool explored = false;
    };
public:
    int dijkstra_shortest_path_length(vector<vector<pair<int, int>>> &in_graph, int from, int to);
};


#endif //COMPLOOK_GRAPHTRAVERSAL_H
