class Solution {

public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        return q(root, 0);
    }
private:
    static int q(TreeNode* node, int depth) {
        if (!node) return depth;
        ++depth;
        return max(q(node->left, depth), q(node->right, depth));
    }
};
