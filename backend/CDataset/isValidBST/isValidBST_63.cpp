class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        return helper(root, numeric_limits<long long int>::min(), numeric_limits<long long int>::max());
    }
    
    bool helper(TreeNode* root, long long int lower, long long int upper) {
        return !root || root->val > lower && root->val < upper && helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
};