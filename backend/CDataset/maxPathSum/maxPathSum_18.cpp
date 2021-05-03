class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
	int maxPathSum(TreeNode* root) {
	int res = INT_MIN;
	dfs(root, res);
	return res;
}

int dfs(TreeNode *node, int &res) {
	if(!node) return 0;
	int l = dfs(node->left, res), r = dfs(node->right, res);
	res = max(res, node->val + l + r);
	return max(0, node->val + max(l, r));
}
};