class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(root->left) {
            TreeNode* l = root->left;
            while(l){
                if(l->val >= root->val) return false;
                l = l->right;
            }
        }
        
        if(root->right){
            TreeNode* r = root->right;
            while(r) {
                if(r->val <= root->val) return false;
                r = r->left;
            }
        }
        
        return isValidBST(root->left)&&isValidBST(root->right);
    }
};