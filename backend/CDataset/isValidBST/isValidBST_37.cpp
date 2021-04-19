class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };bool checkValid(TreeNode* root, TreeNode* lower_bound, TreeNode* upper_bound){
        if (root == NULL) {
            return true;
        }
        
        if (lower_bound) {
            if (root->val >= lower_bound->val) {
                return false;
            }
        }
        
        if (upper_bound) {
            if (root->val <= upper_bound->val) {
                return false;
            }
        }
        
        return checkValid(root->left, root, upper_bound) && checkValid(root->right, lower_bound, root);
        
    }
    
    bool isValidBST(TreeNode* root) {
        return checkValid(root, NULL, NULL);
    }
};