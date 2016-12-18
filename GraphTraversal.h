//
// Created by danza on 26.10.2016.
//

#ifndef COMPLOOK_GRAPHTRAVERSAL_H
#define COMPLOOK_GRAPHTRAVERSAL_H

#include <bits/stdc++.h>

using namespace std;

class GraphTraversal {
private:
    struct Node {
        int value = numeric_limits<int>::max() / 10;
        vector<pair<int, int>> paths;
        bool explored = false;
    };
public:
    struct Edge { int to, length; };
    int dijkstra_shortest_path_length(vector<vector<pair<int, int>>> &in_graph, int from, int to);
    int dijkstra(vector<vector<Edge>> &graph, int source, int target);
};


#endif //COMPLOOK_GRAPHTRAVERSAL_H
