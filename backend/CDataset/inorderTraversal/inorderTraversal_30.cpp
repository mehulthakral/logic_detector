class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        if (!root) return values;
        inorder(root, values);
        return values;        
    }
    
    void inorder(TreeNode* root, vector<int>& values) {
        if (root) {
            inorder(root->left, values);
            values.push_back(root->val);
            inorder(root->right, values);
        }
        return;
        
    }
};
