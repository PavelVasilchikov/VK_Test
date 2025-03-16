#ifndef GRAPH_ALGORITHM_H
#define GRAPH_ALGORITHM_H

#include <vector>
#include <queue>
#include <climits>

const int INF = INT_MAX;

void dijkstra(const std::vector<std::vector<int>>& graph, int start, std::vector<int>& distances);

#endif