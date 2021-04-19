class Solution {

public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        maxd = INT_MIN;
        dfs(root, 1);
        return maxd;
    }
    private:
    int maxd;
    void dfs(TreeNode* root, int d) {
        if (!root->left and !root->right) {
            // leaf node
            maxd = max(maxd, d);
        }
        else {
            // non-leaf node
            if (root->left) {
                dfs(root->left, d+1);
            }
            if (root->right) {
                dfs(root->right, d+1);
            }
        }
    }
};
