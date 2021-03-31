class Solution {
public:
    int count = 0, maxi = 0;
    int dep(TreeNode* root) {
        count++;
        if (root==NULL) {
            maxi = max(maxi, count);
            return 0;
        }
        dep(root->left);
        count--;
        dep(root->right);
        count--;
        
        return maxi-1;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return dep(root);
    }
};
