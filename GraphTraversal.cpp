//
// Created by danza on 26.10.2016.
//

#include "GraphTraversal.h"
#include <bits/stdc++.h>

int GraphTraversal::dijkstra_shortest_path_length(vector<vector<pair<int, int>>> &in_graph, int from, int to) {
    vector<Node> graph(in_graph.size());
    bool explored_all = false;
    int minim, min_i = from;
    for(int i = 0; i < graph.size(); i++)
        for(int j = 0; j < in_graph[i].size(); j++)
            graph[i].paths.push_back(make_pair(in_graph[i][j].first, in_graph[i][j].second));
    graph[from].value = 0;
    graph[from].explored = true;
    while(!explored_all) {
        explored_all = true;
        minim = numeric_limits<int>::max() / 10;
        for(int i = 0; i < graph[from].paths.size(); i++)
            if(graph[from].value + graph[from].paths[i].second < graph[graph[from].paths[i].first].value)
                graph[graph[from].paths[i].first].value = graph[from].value + graph[from].paths[i].second;
        for(int i = 0; i < graph.size(); i++) {
            if(!graph[i].explored) {
                if(graph[i].value <= minim) {
                    explored_all = false;
                    minim = graph[i].value;
                    min_i = i;
                }
            }
        }
        from = min_i;
        graph[min_i].explored = true;
    }
    return graph[to].value;
}