// shortest path in weighted undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
      vector<int> res;
      vector<int> dist(n+1, INT_MAX);
      vector<int> parent(n+1, -1);
      // iota(parent.begin(), parent.end(), 1);
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // dist, neighbour
      vector<vector<pair<int, int>>> adj(n+1);

      for (int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
      }

      min_heap.push({0, 1}); // {distance , source}
      dist[1] = 0;

      while (!min_heap.empty()) {
        int node = min_heap.top().second;
        int node_dist = min_heap.top().first;
        min_heap.pop();

        for (auto it: adj[node]) {
          int neighbour = it.first;
          int weight = it.second;

          if (weight + node_dist < dist[neighbour]) {
            dist[neighbour] = weight + node_dist;
            parent[neighbour] = node;
            min_heap.push({dist[neighbour], neighbour});
          }
        }
      }

      if (dist[n] == INT_MAX) return {-1}; // No path exists

      int i = n;
      while (i != -1) {
        res.push_back(i);
        i = parent[i];
      }
      reverse(res.begin(), res.end());

      // return {dist[n]};
      return res;
    }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(m, vector<int>(3)); // Fix: m edges, not n
  for (int i=0; i<m; i++) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

  Solution sol;
  vector<int> res = sol.shortestPath(n, m, edges);

  for (auto i: res) cout << i << " ";

  return 0;
}