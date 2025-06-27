// 2685. Count the Number of Complete Components

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &vis) {
      vis[node] = true;

      list<int> neighbours = adj[node];
      for (auto neighbour : neighbours) {
        if (!vis[neighbour]) dfs(neighbour, adj, vis);
      }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      int res = 0;
      vector<bool> vis(n, false);

      // creating adjacency
      unordered_map<int, list<int>> adj;
      for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      for (int i=0; i<n; i++){
        if (!vis[i]) {
          dfs(i, adj, vis);
          res++;
        }
      }
      return res;
    }
};

int main() {
  int n = 6;
  vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
  Solution sol;
  int res = sol.countCompleteComponents(n, edges);
  cout << res;
}