class Solution {
private: 
vector<vector<int>> abc;
public:
void helper(TreeNode* root, int level) {
    if(abc.size() < level+1) abc.push_back(vector<int>(1,root->val));
    else abc[level].push_back(root->val);
    if(root->left) helper(root->left,level+1);
    if(root->right) helper(root->right,level+1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root) helper(root,0);
    return abc;   
}
