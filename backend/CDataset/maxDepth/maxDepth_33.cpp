class Solution {
public:
    int dep(TreeNode* root) {
		 if (!root) return 0;
		 return max(dep(root->left), dep(root->right))+1;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return dep(root);
    }
};
