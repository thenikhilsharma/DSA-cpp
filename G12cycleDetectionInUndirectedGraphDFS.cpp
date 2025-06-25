// cycle detection in undirected graph using DFS

#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
using namespace std;

class Solution {
  private:
    bool dfs(int node, int parent, vector<bool> &vis, map<int, list<int>> &adj) {
      vis[node] = true;
      for (auto neighbour : adj[node]) {
        if (!vis[neighbour]) {
          if(dfs(neighbour, node, vis, adj)) return true;
        }
        else if(neighbour != parent) return true;
      }
      return false;
    }

  public:
    bool isCycle(int n, int m, vector<pair<int, int>> &edges){
      // adjacency list
      map<int, list<int>> adj;
      for (auto &edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
      }
      vector<bool> vis(n+1, false);
      return dfs(1, -1, vis, adj);
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