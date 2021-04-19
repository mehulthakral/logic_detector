class Solution {
public:
#include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<int> vec;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
        return vec;
    }
};
