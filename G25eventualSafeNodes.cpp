// 802. Find Eventual Safe States

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // graph is a adjacency list
        int v = graph.size();
        vector<vector<int>> adj(v);
        vector<int> indegree(v, 0);
        for (int i=0; i<v; i++) {
            // i -> it
            // it -> i
            for (auto it: graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i=0; i<v; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};