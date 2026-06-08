// 1928. Minimum Cost to Reach Destination in Time

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
      if (passingFees.size() == 1) return passingFees[0];
      // int e = edges.size(); // number of edges
      int n = passingFees.size(); // number of nodes
      vector<vector<pair<int, int>>> adj(n);
      for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
      }

      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
      vector<int> time_arr(n, INT_MAX), path, parent(n, -1);
      // iota(parent.begin(), parent.end(), 0);
      int total_fees = 0;

      // doing dijkstra's
      min_heap.push({0, 0}); // {time, node}
      time_arr[0] = 0; // time required to reach node 0 (starting node)

      while (!min_heap.empty()) {
        int node = min_heap.top().second;
        int time = min_heap.top().first;
        min_heap.pop();

        for (auto it: adj[node]) {
          if (time + it.second < time_arr[it.first]) {
            time_arr[it.first] = time + it.second;
            parent[it.first] = node;
            min_heap.push({time_arr[it.first], it.first});
          }
        }
      }

      if (time_arr[n-1] == INT_MAX) return -1;
      
      // retrieving the path
      int i = n-1; // ending point
      while (i != -1) {
        total_fees += passingFees[i];
        path.push_back(i);
        i = parent[i];
      }

      return (time_arr[n-1] <= maxTime) ? total_fees : -1;
    }
};