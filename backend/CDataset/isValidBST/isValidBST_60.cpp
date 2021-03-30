//recursive solution with "&" trick
bool isValidBST(TreeNode* root) {
    if (!root)
        return true;
    TreeNode* n = NULL;
    return isValidBST(root, n);
}

bool isValidBST(TreeNode* root, TreeNode* &prev) {
    if (root->left && !isValidBST(root->left, prev))
        return false;
    if (prev && root->val <= prev->val)
        return false;
    prev = root;
    return !root->right || isValidBST(root->right, prev);
}


//morris traversal based solution
public boolean isValidBST(TreeNode root) {
    long prev = Integer.MIN_VALUE;
    --prev;
	TreeNode buf;
	while (root != null) {
		if (root.left != null) {
			buf = root.left;
			while (buf.right != null){
				buf = buf.right;
			}
			buf.right = root;
			buf = root.left;
			root.left = null;
			root = buf;
		}
		else {
		    if (root.val <= prev)
			    return false;
			prev = root.val;
			root = root.right;
		}
	}
	return true;
}