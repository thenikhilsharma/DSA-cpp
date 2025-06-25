// q.push(root element)
// q.front() q.pop()
// check adjacency list for connected nodes
// if not visited - push {that node, curr node}
// if some node is already visited return true

#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isCycle(int n, int m, vector<pair<int, int>> &edges){
      // adjacency list
      map<int, list<int>> adj;
      for (auto &edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
      }
      // for (auto x : adj) {
      //   cout << "\n" << x.first << " : ";
      //   for (auto y : x.second) {
      //     cout << y << " ";
      //   }
      // }

      // bfs algorithm
      vector<bool> vis(n+1, false);
      for (int node=1; node<=n; node++) {
        if (!vis[node]) {
          queue<pair<int, int>> q;
          q.push({1, -1}); // {this node, prev node}
          vis[node] = true;

          while(!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();

            // check adjacency list
            list<int> curr_data = adj[curr];
            for (int neighbour : curr_data) {
              if (!vis[neighbour]) {
                q.push({neighbour, curr});
                vis[neighbour] = true;
              }
              else if (neighbour != parent) { // cycle detected
                return true;
              }
            }
          }
        }
      }
      return false; // no cycle found
    }
};

int main() {
  int n = 7; // no of nodes
  int m = 7; // no of edges
  vector<pair<int, int>> edges = {{1, 2}, {2, 5}, {3, 4}, {5, 7}, {6, 7}, {1, 3}, {3, 6}};
  vector<pair<int, int>> edges2 = {{1, 2}, {2, 5}, {3, 4}, {5, 7}, {1, 3}, {3, 6}};
  Solution sol;
  bool ans = sol.isCycle(n, m, edges);
  bool ans2 = sol.isCycle(n, m, edges2);
  cout << ans << " - " << ans2;
}