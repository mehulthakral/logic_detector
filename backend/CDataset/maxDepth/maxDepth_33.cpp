class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int dep(TreeNode* root) {
		 if (!root) return 0;
		 return max(dep(root->left), dep(root->right))+1;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return dep(root);
    }
};
