//
// Created by danza on 26.10.2016.
//

#include "GraphTraversal.h"
#include <bits/stdc++.h>

GraphTraversal::GraphTraversal(int vertices) {}

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


int GraphTraversal::dijkstra(vector<vector<Edge>> &graph, int source, int target) {
    vector<int> min_distance(graph.size(), INT_MAX);
    set<pair<int, int>> active_vertices;
    min_distance[source] = 0;
    active_vertices.insert({0, source});
    while(!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if(where == target) return min_distance[where];
        active_vertices.erase(active_vertices.begin());
        for(auto ed: graph[where]) {
            if(min_distance[ed.to] > min_distance[where] + ed.length) {
                active_vertices.erase({min_distance[ed.to], ed.to});
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
        }
    }
    return INT_MAX;
}

int GraphTraversal::bfs_distance(vector<vector<int>> &graph, int source, int target) {
    vector<int> distances(graph.size(), INT_MAX);
    distances[source] = 0;
    queue<int> q; q.push(source);
    while(!q.empty()) {
        int where = q.front(); q.pop();
        if(where == target) return distances[target];
        for(int i = 0; i < graph[where].size(); i++) {
            if(distances[graph[where][i]] == INT_MAX) {
                distances[graph[where][i]] = distances[where] + 1;
                q.push(graph[where][i]);
            }
        }
    }
    return INT_MAX;
}

void GraphTraversal::clear_dfs_bitset() { dfs_visited.reset(); }

bool GraphTraversal::dfs_reachable(vector<vector<int>> &graph, int source, int target) {
    if(source == target) return true;
    dfs_visited[source] = true;
    for(int i = 0; i < graph[source].size(); i++)
        if(!dfs_visited[graph[source][i]])
            return dfs_reachable(graph, graph[source][i], target);
    return false;
}










































