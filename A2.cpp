#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to determine if there's a valid path between source and destination
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // If the source and destination are the same, a path exists trivially.
    if (source == destination) {
        return true;
    }

    // Build the adjacency list for the graph.
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // Use BFS to explore the graph and find a path.
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const int& neighbor : graph[current]) {
            // If the neighbor is not visited, check if it's the destination.
            if (!visited[neighbor]) {
                if (neighbor == destination) {
                    return true; // Path to destination found.
                }
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    // If BFS completes without finding a path, return false.
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    vector<vector<int>> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int source, destination;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> destination;

    // Determine if a valid path exists and output the result.
    bool result = validPath(n, edges, source, destination);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
