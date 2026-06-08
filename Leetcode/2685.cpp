// 2685. Count the Number of Complete Components

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, unordered_map<int, unordered_set<int>> &adj, vector<bool> &vis, vector<int> &component) {
        vis[node] = true;
        component.push_back(node);
        
        for (auto neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis, component);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<bool> vis(n, false);
        
        // Create adjacency list using unordered_set for efficient lookup
        unordered_map<int, unordered_set<int>> adj;
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> component;
                dfs(i, adj, vis, component);
                
                // Check if the component is complete
                bool isComplete = true;
                int m = component.size();
                
                // For a complete graph of m nodes, each node should have degree m-1
                for (int node : component) {
                    if (adj[node].size() != m - 1) {
                        isComplete = false;
                        break;
                    }
                }
                
                if (isComplete) {
                    res++;
                }
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