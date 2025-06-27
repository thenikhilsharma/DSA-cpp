#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;  // Mark as visited (in current path)
        for (auto it : adj[node]) {
            if (vis[it] == 1) return true; // Cycle detected
            if (vis[it] == 0 && dfs(it, vis, st, adj)) return true;
        }
        vis[node] = 2;  // Mark as fully processed
        st.push(node);
        return false;
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);  // 0=unvisited, 1=in current path, 2=processed
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0 && dfs(i, vis, st, adj)) {
                return {};  // Cycle detected, return empty list
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> adj(V);  // Initialize for V nodes
    adj[0] = {1, 2, 3};         // 0 → 1, 0 → 2, 0 → 3
    // Other nodes (1, 2, 3) have no outgoing edges
    
    Solution sol;
    vector<int> ans = sol.topoSort(V, adj);
    
    if (ans.empty()) {
        cout << "Cycle detected! Topological sort not possible." << endl;
    } else {
        for (auto i : ans) cout << i << " ";  // Output: 0 1 2 3 (or similar)
    }
    return 0;
}