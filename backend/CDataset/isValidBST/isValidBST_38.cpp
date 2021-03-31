bool isValidBST(TreeNode* root) {
	if (root == 0)
		return true;
	bool flag = true;
	int pre;
	stack<TreeNode *>s;
	while (!s.empty() || root != 0) {
		if (root != 0) {
			s.push(root);
			root = root->left;
		}
		else {
			root = s.top();
			s.pop();
			if (flag) {
				flag = false;
			}
			else if (root->val <= pre)
				return false;
			pre = root->val;
			root = root->right;
		}
	}
	return true;
}
