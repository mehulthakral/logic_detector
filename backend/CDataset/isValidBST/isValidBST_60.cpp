class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };//recursive solution with "&" trick
bool isValidBST(TreeNode* root) {
    if (!root)
        return true;
    TreeNode* n = NULL;
    return isValidBST(root, n);
}

bool isValidBST(TreeNode* root, TreeNode* &prev) {
    if (root->left && !isValidBST(root->left, prev))
        return false;
    if (prev && root->val <= prev->val)
        return false;
    prev = root;
    return !root->right || isValidBST(root->right, prev);
}
};