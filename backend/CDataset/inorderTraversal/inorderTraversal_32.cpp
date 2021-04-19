class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return std::vector<int>{};
        std::cout << root->val << '\n';
        std::vector<int> left, right;
        if (root->left) left = inorderTraversal(root->left);
        if (root->right) right = inorderTraversal(root->right);
        left.push_back(root->val);
        left.insert(end(left), begin(right), end(right));
        return left;
    }
};
