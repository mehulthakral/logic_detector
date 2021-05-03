class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root, TreeNode* nmin = nullptr, TreeNode* nmax = nullptr) {
        if(!root) 
            return true;
        if(nmin && root->val <= nmin->val)
            return false;
        if(nmax && root->val >= nmax->val)
            return false;
        return isValidBST(root->left, nmin, root) && isValidBST(root->right, root, nmax);
    }
};
