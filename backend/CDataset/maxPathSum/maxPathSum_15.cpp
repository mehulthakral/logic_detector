class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = root->val;
        getMaxSumPath(root, &max_sum);
        return max_sum;
    }
private:
    int getMaxSumPath(TreeNode* node, int* max_sum) {
        if (node == nullptr) return 0;
        auto l = max(getMaxSumPath(node->left, max_sum), 0);
        auto r = max(getMaxSumPath(node->right, max_sum), 0);
        *max_sum = max(*max_sum, node->val + l + r);
        return node->val + max(l, r);
    }
};
