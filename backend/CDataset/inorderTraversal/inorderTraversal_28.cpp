void traverse(TreeNode* t,vector<int> &v){
    if(t==nullptr)return;
    if(t->left!=nullptr)traverse(t->left,v);
    v.push_back(t->val);
    if(t->right!=nullptr)traverse(t->right,v);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vect;
        traverse(root,vect);
        return vect;
    }
};
