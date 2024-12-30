#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Create an adjacency list
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& time : times) {
        graph[time[0]].emplace_back(time[1], time[2]);
    }

    // Min-heap to store (time, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.emplace(0, k);

    // Distance array to keep track of the shortest time to each node
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    while (!minHeap.empty()) {
        auto [currentTime, node] = minHeap.top();
        minHeap.pop();

        // If this time is already longer than the shortest known time, skip
        if (currentTime > dist[node]) continue;

        // Traverse neighbors
        for (const auto& [neighbor, weight] : graph[node]) {
            if (currentTime + weight < dist[neighbor]) {
                dist[neighbor] = currentTime + weight;
                minHeap.emplace(dist[neighbor], neighbor);
            }
        }
    }

    // Find the maximum time needed to reach any node
    int maxTime = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX) return -1; // If a node is unreachable
        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}

int main() {
    int n, m, k;
    cout << "Enter the number of nodes (n): ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> times(m, vector<int>(3));
    cout << "Enter the edges (source, target, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    cout << "Enter the starting node (k): ";
    cin >> k;

    int result = networkDelayTime(times, n, k);
    cout << "The minimum time for all nodes to receive the signal is: " << result << endl;

    return 0;
}
