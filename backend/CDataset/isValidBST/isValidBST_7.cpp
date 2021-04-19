class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        // checking the left branch
        bool isLeftChildValueBalanced = root->left && root->left->val > minVal && root->left->val < root->val;
        bool isLeftBranchBalanced = root->left && isValidBST(root->left, minVal, min(maxVal, (long)root->val));
        // a valid left branch: either NULL or both its root and its children are balanced
        bool isBalancedLeft = !root->left || isLeftChildValueBalanced && isLeftBranchBalanced;
        // checking the right branch
        bool isRightChildValueBalanced = root->right && root->right->val > root->val && root->right->val < maxVal;
        bool isRightBranchBalanced = root->right && isValidBST(root->right, max(minVal, (long)root->val), maxVal);
        // a valid right branch: either NULL or both its root and its children are balanced
        bool isBalancedRight = !root->right || isRightChildValueBalanced && isRightBranchBalanced;
        return isBalancedLeft && isBalancedRight;
    }
};