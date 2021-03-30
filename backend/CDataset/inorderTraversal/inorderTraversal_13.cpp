class Solution {
public:
   void pot(TreeNode*root,vector<int>&v)
    {    if(root==NULL) return;
         pot(root->left,v);
         v.push_back(root->val);
         pot(root->right,v);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        pot(root,v);
        return v;
    }
};
