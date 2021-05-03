class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    void recur(TreeNode* root, bool& res, int& prev, bool& firstElem) {
        if (!root) return;
        if (root->left) recur(root->left, res, prev, firstElem);
        if (!firstElem) { // first element, so don't do anything
            firstElem = true;
        } else { // henceforth check for small or not
            if (root->val > prev) {
                res = res && true;
            } else {
                res = res && false;
            }    
        }
        prev = root->val;
        if (root->right) recur(root->right, res, prev, firstElem);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool res = true;
        bool firstElem = false;
        int prev;
        recur(root, res, prev, firstElem);
        return res;
    }
};