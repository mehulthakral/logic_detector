class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->right && cur->val >= cur->right->val) {
                return false;
            }

            if (!cur->left) {
                cur = cur->right;
            }
            else {
                TreeNode * prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right) {
                    prev->right = nullptr;
                    cur = cur->right;
                } else {
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        return true;
    }
};
