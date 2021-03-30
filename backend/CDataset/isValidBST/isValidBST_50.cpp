class Solution {
private:
    inline bool validate(TreeNode* node, long min, long max) {
        if (!node) return true;
        long val = node->val;
        if (val >= max || val <= min) {
            return false;
        }
        return validate(node->left, min, val) && validate(node->right, val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};