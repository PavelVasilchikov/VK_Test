#include <iostream>
#include <fstream>

#include "graph_algorithm.h"

using namespace std;

int main() {

    ifstream file("graph.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int numberOfVertices, numberOfEdges;
    file >> numberOfVertices >> numberOfEdges;

    vector<vector<int>> graph(numberOfVertices);
    for (int i = 0; i < numberOfEdges; ++i) {
        
        int firstVertex, secondVertex;

        file >> firstVertex >> secondVertex;

        graph[firstVertex].push_back(secondVertex);
        graph[secondVertex].push_back(firstVertex);
    }

    int start;
    file >> start;

    vector<int> distances;
    dijkstra(graph, start, distances);

    for (int i = 0; i < numberOfVertices; ++i) {
        cout << distances[i] << endl;
    }
    cout << endl;

    file.close();
    return 0;
}