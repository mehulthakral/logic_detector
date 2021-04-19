class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()) {
            int m = q.size();
            TreeNode* tmp;
            for(int i = 0; i < m; ++i) {
                tmp = q.front();
                q.pop();
                v.emplace_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            ans.emplace_back(v);
            v.clear();
        }
        return ans;
    }
};
