class Solution {
public:
    bool isValid(TreeNode* root,TreeNode* min,TreeNode* max)
    {
        if(root == NULL) return true;
        
        if(min!=NULL && min->val >= root->val)
            return false;
        
        if(max!=NULL && max->val <= root->val)
            return false;
        
        return isValid(root->left,min,root)&&isValid(root->right,root,max);
        
    }
    bool isValidBST(TreeNode* root) {        
         
        return isValid(root,NULL,NULL);     
    }
};
