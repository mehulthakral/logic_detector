class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxPathSum(TreeNode* root) {
        int maxdownsum;
        int h;
        helper(root, maxdownsum, h);
        return rst;
    }
private:
    int rst = INT_MIN;
    
    void helper(TreeNode* root, int& maxdownsum, int& h) {
        if (!root) {
            // null
            maxdownsum = 0;
            h = 0;
            return ;
        }
        int ldownsum, rdownsum; // max sum for a path that starts from l/r child node and goes downward only
        int lh, rh; // height for l/r subtree
        helper(root->left, ldownsum, lh);
        helper(root->right, rdownsum, rh);
        // figure out height and maxdownsum for root node
        h = max(lh, rh) + 1;
        maxdownsum = max(max(ldownsum, 0), max(rdownsum, 0)) + root->val;
        // calculate max path that passes root node
        rst = max(rst, max(ldownsum, 0) + max(rdownsum, 0) + root->val);
    }
    
};