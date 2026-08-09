// https://leetcode.com/problems/weighted-sum-of-a-tree/description/

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> child(n);
        for (int i = 1; i < n; i++) child[parent[i]].push_back(i);
        vector<int> d(n, 0);
        queue<int> q;
        q.push(0);
        d[0] = 1;
        int h = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            h = max(h, d[u]);
            for (int v : child[u]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        long long wt = 0;
        for (int i = 0; i < n; i++) wt += (long long)nums[i] * (h - d[i] + 1);
        return wt;
    }
};