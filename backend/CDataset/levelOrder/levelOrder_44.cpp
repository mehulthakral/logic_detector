class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int depth) {
        if(!root)
            return;
        if(ans.size() == depth)
            ans.emplace_back(vector<int>());
        ans[depth].emplace_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
