#include "graph_algorithm.h"

using namespace std;

void dijkstra(const vector<vector<int>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int dist = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (dist > distances[vertex]) continue;

        for (int neighbor : graph[vertex]) {
            int new_dist = dist + 1;
            if (new_dist < distances[neighbor]) {
                distances[neighbor] = new_dist;
                pq.push({ new_dist, neighbor });
            }
        }
    }
}