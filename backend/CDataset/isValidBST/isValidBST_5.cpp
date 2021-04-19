class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        return (!root->left || root->left->val > minVal && root->left->val < root->val && isValidBST(root->left, minVal, min(maxVal, (long)root->val))) && (!root->right || root->right->val > root->val && root->right->val < maxVal && isValidBST(root->right, max(minVal, (long)root->val), maxVal));
    }
};