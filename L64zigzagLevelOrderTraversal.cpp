// leetcode q103

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int len = q.size();
            vector<int> ans(len);

            for(int i=0; i<len; i++){
                TreeNode* node = q.front();
                q.pop();

                int index = flag ? i : len - i - 1;

                ans[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(ans);
            flag = !flag;
        }

        return res;
    }
};