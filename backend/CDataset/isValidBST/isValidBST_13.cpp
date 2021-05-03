class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        return checkBST(root,prev);
    }       
    bool checkBST(TreeNode* root,TreeNode*& prev){
        if(root==NULL){
            return true;
        }
        if(!checkBST(root->left,prev)){
            return false;
        }
        if(prev!=NULL && root->val<=prev->val){
            return false;
        }
        prev=root;
        return checkBST(root->right,prev);
        
    }
};
