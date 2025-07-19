// Floyd Warshall Algorithm
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> floydWarshall(int V, int E, vector<vector<int>>& edges) {
        // Initialize distance matrix
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
        
        // Set distance from each vertex to itself as 0
        for (int i = 0; i < V; ++i) dist[i][i] = 0;
        
        // Set distances based on edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            dist[u][v] = min(dist[u][v], weight); // Handle multiple edges
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        return dist;
    }
};

int main() {
    int V= 4; // Number of vertices
    int E = 6; // Number of edges
    
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 10},
        {1, 2, 3},
        {1, 3, 2},
        {2, 3, 1},
        {3, 0, 4}
    };
    Solution sol;
    vector<vector<int>> dist = sol.floydWarshall(V, E, edges);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}