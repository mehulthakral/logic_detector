class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int dfs(TreeNode* root, int &globalmax)
    {
        if(root==NULL) return 0;
        
        int left = dfs(root->left, globalmax);
        int right = dfs(root->right, globalmax);
        
        int straightPath = max(max(left, right) + root->val, root->val);
        
        int trianglePath = max(straightPath, left + right + root->val);
        
        globalmax = max(globalmax, trianglePath);
        
        return straightPath;
    }
    int maxPathSum(TreeNode* root) 
	{
        int globalmax = INT_MIN;
        dfs(root, globalmax);
        return globalmax;
    }
};
