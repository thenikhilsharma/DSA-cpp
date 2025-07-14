// cycle detection in directed graph using breadth-first search / kahn's algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> topoSort(int v, vector<vector<int>> &adj) {
        int inDegree[v] = {0};
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) inDegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }

public:
    bool isCycle(int v, vector<vector<int>> &adj) {
        vector<int> topo = topoSort(v, adj);
        return static_cast<int>(topo.size()) != v; // Returns true if cycle exists, false otherwise
    }
};

int main() {
    int v = 4;
    vector<vector<int>> adj(v);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0); // Creates a cycle: 0 -> 1 -> 2 -> 3 -> 0

    Solution sol;
    cout << sol.isCycle(v, adj); // Output: 1 (true, cycle exists)

    return 0;
}