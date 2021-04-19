class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
       return !root?0:max(maxDepth(root -> right),maxDepth(root -> left))+1; 
    }
};
