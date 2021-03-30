class Solution {
public:
    int maxDepth(TreeNode* root) {
        // root is null
        if (root == NULL)
            return 0;
        
        // root is a leaf node
        if ((root!=NULL) && (root->left==NULL) && (root->right==NULL))
            return 1;
        
        // root has only right subtree
        if (root->left==NULL)
            return maxDepth(root->right) + 1;
        
        // root has only left subtree
        if (root->right==NULL)
            return maxDepth(root->left) + 1;
        
        // Return max depth of left and right subtree
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};