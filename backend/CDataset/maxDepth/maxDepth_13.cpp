class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode *root) {
    int leftHeight, rightHeight;

    if (!root)
        return 0;

    leftHeight = maxDepth(root->left);
    rightHeight = maxDepth(root->right);

    return max(leftHeight, rightHeight) + 1;
}
};