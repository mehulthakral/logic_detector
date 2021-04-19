class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };bool isValidBST(TreeNode* root) {
  if (!root) return true;

  if (!isValidBST(root->left)) return false;
  static long pre=LONG_MIN;
  if (pre>=(long)root->val) return false;
  pre = root->val;

  return isValidBST(root->right);
}
};