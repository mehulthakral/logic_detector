class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        int ret = 0;
        int depth = 0;
        auto cur = root;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
                ++depth;
            }
            else {
                auto prev = cur->left;
                int dist = 1;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                    ++dist;
                }
                if (prev->right) {
                    prev->right = nullptr;
                    cur = cur->right;
                    ret = max(ret, depth);
                    depth -= dist;
                }
                else {
                    prev->right = cur;
                    cur = cur->left;
                    ++depth;
                }
            }
        }
        return max(ret, depth);
    }
};