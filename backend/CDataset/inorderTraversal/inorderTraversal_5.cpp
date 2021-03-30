class Solution {
public:
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return inorder;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        return inorder;
    }
};
