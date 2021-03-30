class Solution {
private:
    int dfs(TreeNode* root, int& maxsum) {
        if(!root) return 0;
        int l = max(0,dfs(root->left,maxsum));
        int r = max(0,dfs(root->right,maxsum));
        maxsum = max(l+r+root->val, maxsum);
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
};