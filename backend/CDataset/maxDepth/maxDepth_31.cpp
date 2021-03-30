    int maxDepth(TreeNode* root) {
        return !root ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
	// We go as deep as possible, into the call stack. When no root exists we unwind
	// keeping track of the max height between the left and right subtrees.
	// For every level we unwind we add 1 to signify 1 level.
