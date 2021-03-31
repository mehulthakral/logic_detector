class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* root, int &ans)
    {
        if(!root) return 0;
        int l=max(0,dfs(root->left,ans));
        int r=max(0,dfs(root->right,ans));      
        ans=max(ans, root->val+l+r);
        return root->val + max(l,r);
    }
};
