// Prim's Algorithm
// Time Complexity: O(E log V)
// Space Complexity: O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Create an adjacency list
        vector<vector<pair<int, int>>> graph(V);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        // Min-heap priority queue to select the minimum weight edge
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(V, false);
        int totalCost = 0;

        // Start from the first vertex
        pq.push({0, 0}); // {cost, vertex}

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue; // Skip if already included in MST

            inMST[u] = true; // Include this vertex in MST
            totalCost += cost;

            // Explore all adjacent vertices
            for (const auto& [v, weight] : graph[u]) {
                if (!inMST[v]) {
                    pq.push({weight, v});
                }
            }
        }

        return totalCost;
    }
};

int main() {
    vector<vector<int>> edges = {
        {0, 1, 1}, {0, 2, 3}, {1, 2, 2}, {1, 3, 4},
        {2, 3, 5}, {3, 4, 6}, {4, 5, 7}, {5, 6, 8}
    };
    Solution sol;
    int result = sol.minCostConnectPoints(points);
    cout << "Minimum cost to connect all points: " << result << endl;
    return 0;
}