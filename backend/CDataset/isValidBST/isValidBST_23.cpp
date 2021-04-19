class Solution {
public:

#include<vector>
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<int> order;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inOrder(root);
        for (size_t i = 0; i < order.size() - 1; i++) {
            if (order[i] >= order[i + 1]) return false;
        }
        return true;
    }
    
    void inOrder(TreeNode* root) {
        if (!root) return ;
        inOrder(root->left);
        this->order.push_back(root->val);
        inOrder(root->right);
    }
};
