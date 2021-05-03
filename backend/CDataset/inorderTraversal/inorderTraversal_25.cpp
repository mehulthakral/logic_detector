class Solution {
public:
#include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(&v,root);
        return v;
    } 
    void inorder(vector<int> *v,TreeNode* root)
{   if(root==NULL)
        return ;
    if(root->left!=NULL)
        inorder(v,root->left);
    v->push_back(root->val);
    if(root->right!=NULL)
        inorder(v,root->right);
    
    return;
}
};
