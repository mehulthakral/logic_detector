class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    //as long as this is smaller than the lowest minimum of integer then is fine.
    long int previousValue = -2147483650;
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool isLeftBST = isValidBST(root->left);
        if (root->val <= previousValue) return false;
        previousValue = root->val;
        bool isRightBST = isValidBST(root->right);
        return isLeftBST && isRightBST;
    }
};
