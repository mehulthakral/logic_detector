class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return isValid(root, pre);
    }
    
    bool isValid(TreeNode* root, TreeNode* &pre){
        if(!root) return true;
        if(!isValid(root->left, pre)) return false;
        if(pre && root->val <= pre->val) return false;
        pre = root;
        return isValid(root->right, pre);
    }
};
