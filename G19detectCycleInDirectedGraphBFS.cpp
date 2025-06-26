// prepare adjacency list
// vis array && path vis array
// if one element is visited twice in path vis array - cycle is detected

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

  private:
    bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &vis, vector<bool> &pathVis) {
      vis[node] = true;
      pathVis[node] = true;

      list<int> neighbours = adj[node];
      for (auto neighbour : neighbours) {
        if (!pathVis[neighbour] && !vis[neighbour]) {
          dfs(neighbour, adj, vis, pathVis);
        }
        else {
          return true;
        }
      }
      pathVis[node] = false; // backtrack
      return false;
    }

  public:
    bool isCycle(vector<pair<int, int>> &mpp, int n){
      // prepare adjacency list
      unordered_map<int, list<int>> adj;
      vector<bool> vis(n+1);
      for (auto i: mpp) {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
      }

      for (int i=1; i<=n; i++){
        if (!vis[i]) {
          vector<bool> pathVis(n+1);
          if (dfs(i, adj, vis, pathVis)) return true;
        }
      }
      return false;
    }
};

int main() {
  vector<pair<int, int>> mpp = {{1, 2}, {2, 3}, {3, 4}, {3, 7}, {4, 5}, {7, 5}, {5, 6}, {8, 9}, {9, 10}, {10, 8}, {8, 2}};
  Solution sol;
  cout << sol.isCycle(mpp, 10);
}