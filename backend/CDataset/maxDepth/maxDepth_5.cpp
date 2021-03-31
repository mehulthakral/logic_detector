class Solution {
private:
    static int q(TreeNode* node, int depth) {
        if (!node) return depth;
        ++depth;
        return max(q(node->left, depth), q(node->right, depth));
    }
public:
    int maxDepth(TreeNode* root) {
        return q(root, 0);
    }
};
