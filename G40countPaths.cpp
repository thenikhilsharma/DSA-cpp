// 1976. Number of Ways to Arrive at Destination
// prepare adjacency list
// Dijkstra's algorithm to find shortest paths
// Time Complexity: O((N + E) log N)
// Space Complexity: O(N + E)

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
      // prepare adjacency list
      vector<vector<pair<int, int>>> adj(n);
      for (int i=0; i<roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
      }

      // Dijkstra's algorithm to find shortest paths
      vector<long long> dist(n, LLONG_MAX);
      priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {dist, node}
      vector<int> ways(n, 0);
      dist[0] = 0; // setting source node distance to 0
      ways[0] = 1; // there's one way to reach the source node
      pq.push({0, 0}); // {distance, node}

      while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue; // skip if we already found a better path
        for (auto& [neighbor, weight] : adj[node]) {
          if (dist[node] + weight < dist[neighbor]) {
            dist[neighbor] = dist[node] + weight;
            ways[neighbor] = ways[node]; // update ways to reach neighbor
            pq.push({dist[neighbor], neighbor});
          } else if (dist[node] + weight == dist[neighbor]) {
            ways[neighbor] = (ways[neighbor] + ways[node]) % MOD; // add ways to reach neighbor
          }
        }
      }
      return ways[n - 1]; // return number of ways to reach destination node
    }
};

int main() {
    int n = 7; // number of nodes
    vector<vector<int>> roads = {
        {0, 1, 1}, {0, 2, 2}, {1, 3, 2}, {1, 4, 3},
        {2, 4, 1}, {3, 5, 1}, {4, 5, 2}, {5, 6, 1}
    };
    Solution sol;
    int result = sol.countPaths(n, roads);
    cout << "Number of ways to arrive at destination: " << result << endl;
    return 0;
}