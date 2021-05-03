class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
	if(!root) return true;
	if(root->val <= min || root->val >= max) return false;
	return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}
};