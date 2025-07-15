// priority queue (min heap) {dist, node}
// dist = [intmax, intmax, ....]
// dist[source] = 0; and push in priority queue
// get the top check adjacency list - visit neighbours - compare distance - update dist
// do this until pq is empty

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
      // adjacency list
      vector<vector<pair<int, int>>> adj(V);
      for (int i=0; i<edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
      }

      // priority queue
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

      vector<int> dist(V, INT_MAX);
      dist[src] = 0;
      min_heap.push({0, src});

      while (!min_heap.empty()) {
        int node = min_heap.top().second;
        int node_dist = min_heap.top().first;
        min_heap.pop();

        if (node_dist > dist[node]) continue;
        for (auto it: adj[node]) {
          int neighbor = it.first;
          int weight = it.second;

          if (node_dist + weight < dist[neighbor]) {
            dist[neighbor] = node_dist + weight;
            min_heap.push({node_dist + weight, neighbor});
          }
        }
      }
      
      return dist;
    }
};