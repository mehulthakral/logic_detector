class Solution {
public:
    #include<vector>

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
	int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    void helper(vector<vector<int>> &ans, TreeNode *root,int level){
        if(!root) return;
        ans[level].push_back(root->val);
        helper(ans,root->left,level+1);
        helper(ans,root->right,level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans(height(root));
        helper(ans,root,0);
        return ans;
    }
};