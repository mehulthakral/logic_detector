class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        return dfs(root);
    }
    int dfs(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        return 1;
        int left = INT_MIN, right = INT_MIN;
        if(root->left != NULL)
        left = dfs(root->left) + 1;
        if(root->right != NULL)
        right = dfs(root->right) + 1;
        return max(left, right);
    }
};