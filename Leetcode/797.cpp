// 797. All Paths From Source to Target
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &path, vector<vector<int>> &res, int target) {
        path.push_back(node);
        
        if (node == target) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        
        for (auto &neighbor : adj[node]) {
            dfs(neighbor, adj, path, res, target);
        }
        
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adj;
        vector<vector<int>> res;
        vector<int> path;
        
        // Build adjacency list
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        int target = graph.size() - 1; // The target is the last node
        dfs(0, adj, path, res, target); // Start from node 0
        
        return res;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    Solution sol;
    vector<vector<int>> res = sol.allPathsSourceTarget(graph);
    for (auto &i: res) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}