class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        DFS(res, root, 0);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, TreeNode* root, int level){
        if(!root) return;
        if(level == res.size()) res.push_back(vector<int>());
        res[level].push_back(root->val);
        DFS(res, root->left, level + 1);
        DFS(res, root->right, level + 1);
    }
};
