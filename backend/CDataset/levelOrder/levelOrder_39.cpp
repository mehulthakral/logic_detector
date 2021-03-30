vector<vector<int>> levelOrder(TreeNode* root) {
vector<vector<int>> vec;
vector<int> temp;
queue<TreeNode*> q;
queue<TreeNode*> q1;
if (root != NULL) {
	q.push(root);
	while (!q.empty() || !q1.empty()) {
		while (!q.empty()) {
			auto n = q.front();
			q.pop();
			temp.push_back(n->val);
			if (n->left != NULL)
				q1.push(n->left);
			if (n->right != NULL)
				q1.push(n->right);
		}
		vec.push_back(temp);
		temp.clear();
		swap(q1, q);
	}

}
return vec;
