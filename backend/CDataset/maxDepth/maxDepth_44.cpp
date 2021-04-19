class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
    	if(root == NULL)return 0;
        int len_left = maxDepth(root->left);
        int len_right = maxDepth(root->right);
        return max(len_left, len_right) + 1;
    }
};
