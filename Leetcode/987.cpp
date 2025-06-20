//987. Vertical Order Traversal of a Binary Tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        map<pair<int, int>, vector<int>> axis; // <x-axis, y-axis>, data
        dfs(root, 0, 0, axis);

        // Find min and max x to determine res size
        int min_x = INT_MAX, max_x = INT_MIN;
        for (auto& entry : axis) {
            min_x = min(min_x, entry.first.first);
            max_x = max(max_x, entry.first.first);
        }
        vector<vector<int>> res(max_x - min_x + 1);

        for (auto &element : axis) {
            int x = element.first.first;
            vector<int> values = element.second;
            sort(values.begin(), values.end());
            // res[x-min_x].insert(res[x-min_x].end(), values.begin(), values.end());
            for (int val : values) res[x - min_x].push_back(val);
        }

        return res;
    }

    void dfs(TreeNode* root, int x, int y, map<pair<int, int>, vector<int>>& axis) {
        if (!root) return;

        axis[{x, y}].push_back(root->val);
        if (root->left) dfs(root->left, x - 1, y + 1, axis);
        if (root->right) dfs(root->right, x + 1, y + 1, axis);
    }
};