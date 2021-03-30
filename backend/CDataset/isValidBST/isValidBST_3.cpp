class Solution {
public:
    TreeNode* prev = NULL;
    int isBst = true;
    
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        
        inorder(root->left);
        
        if(prev == NULL){
            prev = root;
        }
        
        else{
            if(prev->val >= root->val){
                isBst = false;
                return;
            }
            else{
                prev = root;
            }
        }
        
        inorder(root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return isBst;
    }
};
