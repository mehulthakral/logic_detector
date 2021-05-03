class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
    
    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
};
