class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if(root == null)return 0;
        int len_left = maxDepth(root->left);
        int len_right = maxDepth(root->right);
        return max(len_left, len_right) + 1;
    }
};
