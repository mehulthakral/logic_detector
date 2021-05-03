class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        return root==NULL ? 0 : 1+max(maxDepth(root->left),maxDepth(root->right));
        
    }
};
