// BELLMAN FORD ALGORITHM - Find the shortest path from a source vertex to all other vertices in a weighted graph with negative weights.
// This implementation uses a vector of pairs to represent the graph and handles negative weights.
// Time Complexity: O(V * E)
// Space Complexity: O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, int E, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return {}; // Return empty vector if a negative cycle is detected
            }
        }

        return dist;
    }
};

int main() {
  vector<vector<int>> edges = {
    {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
    {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
  };
  int V = 5; // Number of vertices
  int E = edges.size();
  int src = 0; // Source vertex
  Solution sol;
  vector<int> dist = sol.bellmanFord(V, E, edges, src);
  if (!dist.empty()) {
    for (int i = 0; i < V; ++i) cout << i << " : " << dist[i] << endl;
  }
}