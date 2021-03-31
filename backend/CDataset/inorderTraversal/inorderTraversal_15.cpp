class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        return v;
    }
    void helper(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
            return ;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
};
