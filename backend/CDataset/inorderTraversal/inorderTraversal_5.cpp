class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return inorder;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        return inorder;
    }
};
