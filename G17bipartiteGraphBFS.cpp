class Solution {
private:
    bool bfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (auto it : adj[n]) {
                if (vis[it] == -1) {
                    vis[it] = !vis[n];
                    q.push(it);
                } else if (vis[it] == vis[n]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, -1);
        for (int i = 0; i < v; i++) {
            if (vis[i] == -1) {
                if (!bfs(i, graph, vis)) return false;
            }
        }
        return true;
    }
};