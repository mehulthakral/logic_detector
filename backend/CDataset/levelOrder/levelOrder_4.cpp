class Solution {
public:
    #include<vector>

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
vector<vector<int>> levelOrder(TreeNode* root) {
	if (!root)
		return {};
	vector<vector<int>> res;
	queue< pair<TreeNode*, int> > q; // node, level
	q.push( { root, 0 } );
	while (!q.empty()) {
		auto [node, level] = q.front();
		q.pop();

		if (res.size() <= level)
			res.push_back({});

		res[level].push_back(node->val);
		if (node->left)
			q.push( { node->left, level + 1 } );
		if (node->right)
			q.push( { node->right, level + 1 } );
	}
	return res;
}
};