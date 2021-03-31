class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValid(root->left, root->val, true) || !isValid(root->right, root->val, false)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
    
    bool isValid(TreeNode* root, int bound, bool isLeft){
        return !root || (isLeft ? root->val < bound : root->val > bound ) && isValid(root->left, bound, isLeft) && isValid(root->right, bound, isLeft);
    }
};
