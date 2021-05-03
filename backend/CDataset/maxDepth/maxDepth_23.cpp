class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
};
