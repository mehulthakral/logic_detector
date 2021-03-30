 bool isValidBST(TreeNode *root) {
        // use long min and long max if the value in tree is int
        return isValidBSTRec(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBSTRec(TreeNode* root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        
        if (root->val <= min || root->val >= max) {
            return false;
        }
        
        bool left = isValidBSTRec(root->left, min, root->val);
        if (left == true) {
            return isValidBSTRec(root->right, root->val, max);
        }
        return false;
    }