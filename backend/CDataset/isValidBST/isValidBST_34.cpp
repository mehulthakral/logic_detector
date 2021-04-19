class Solution {
public:
#include<vector>
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    void inorder(TreeNode* root, vector<int>& tree) {
        if(!root) return;
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> tree;
        inorder(root, tree);
        return is_sorted(tree.begin(), tree.end(), [&](int a, int b){return a <= b;});
    }
};
