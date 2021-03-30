class Solution {
public:
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        // checking the left branch
        bool isBalancedLeft = !root->left || root->left->val > minVal && root->left->val < root->val && isValidBST(root->left, minVal, min(maxVal, (long)root->val));
        // checking the right branch
        bool isBalancedRight = !root->right || root->right->val > root->val && root->right->val < maxVal && isValidBST(root->right, max(minVal, (long)root->val), maxVal);
        return isBalancedLeft && isBalancedRight;
    }
};