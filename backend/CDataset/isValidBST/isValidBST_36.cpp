class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
	bool isValidBST(TreeNode* n, long lo = LONG_MIN, long hi = LONG_MAX) {
	return !n || (n->val > lo && n->val < hi && isValidBST(n->left, lo, n->val) && isValidBST(n->right, n->val, hi));
}
};