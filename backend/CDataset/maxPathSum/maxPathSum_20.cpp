class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxPath( TreeNode* root ){
        if( !root )
            return 0;
        return max(root->val ,root->val + max(maxPath(root->left),maxPath(root->right) ));
    }
    int maxPathSum(TreeNode* root) {
            if( !root )
                return INT_MIN;
            return max(root->val + maxPath(root->right),max(root->val + maxPath(root->left),max(root->val,max(root->val + maxPath(root->left) + maxPath(root->right),max(maxPathSum(root->left),maxPathSum(root->right))))));
    }
};
