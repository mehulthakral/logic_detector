class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        if( !root )
            return 0;

        return 1 + max( maxDepth( root->left ), maxDepth( root->right ) );
    }
};