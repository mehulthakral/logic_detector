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
        dfs(root, 0, ans);
        return ans;
    }
private:
    void dfs(TreeNode* node, int level, vector<vector<int>> &ans) {
        if(!node) {
            return;
        }
        while(level >= ans.size()) {
            ans.push_back({});
        }
        
        ans[level].push_back(node->val);
        
        dfs(node->left, level+1, ans);
        dfs(node->right, level+1, ans);
    }
};
