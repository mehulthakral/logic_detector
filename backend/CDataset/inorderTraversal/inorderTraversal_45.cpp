class Solution {
    public:
    vector inorderTraversal(TreeNode* root) {
        vector lis;
        if(root == NULL){
            return lis;
        }
        traversal(root, lis);
        return lis;
    }
    
    void traversal(TreeNode* root, vector& lis){
        if(root == NULL){
            return;
        }
        
        traversal(root -> left, lis);
        lis.push_back(root -> val);
        traversal(root -> right, lis);   
    }
};