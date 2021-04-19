class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    void solve(TreeNode* root,int ma,int &ans)
    {
        if(root==NULL)
            return;
        ans=max(ma,ans);
        if(root->left)
            solve(root->left,ma+1,ans);
        if(root->right)
            solve(root->right,ma+1,ans);
    }
    int maxDepth(TreeNode* root) {
        int ma=1;
        int ans=0;
        solve(root,ma,ans);
        return ans;
    }
};
