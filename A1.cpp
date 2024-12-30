#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (source == destination) {
        return true; // If source and destination are the same, the path exists.
    }

    // Create an adjacency list for the graph.
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // BFS to check for a path from source to destination.
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const int& neighbor : graph[current]) {
            if (!visited[neighbor]) {
                if (neighbor == destination) {
                    return true; // Found the destination.
                }
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // No path found.
}

int main() {
    int n, m;
    cout << "Enter number of nodes (n): ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int source, destination;
    cout << "Enter source: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> destination;

    bool result = validPath(n, edges, source, destination);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
