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
        vector<int> vect;
        traverse(root,vect);
        return vect;
    }
    void traverse(TreeNode* t,vector<int> &v){
    if(t==nullptr)return;
    if(t->left!=nullptr)traverse(t->left,v);
    v.push_back(t->val);
    if(t->right!=nullptr)traverse(t->right,v);
}
};
