// topological sort using bfs

// linear ordering between elements such that if an edge exists between u and v
// then u occurs before v

// algo
/*
1. prepare a in degree vector or map (calc the indegree)
2. prepare a queue insert all the elements having indegree 0
3. reduce the in degree of adjacent node
4. if adjacent nodes have in degree = 0 put them in queue as well
5. pop queue to answer array
*/

// TC : O(v+e)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
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
};

int main() {
    int v = 4;
    vector<vector<int>> adj(v);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    Solution sol;
    vector<int> res = sol.topoSort(v, adj);
    for (auto i : res) cout << i << " ";

    return 0;
}