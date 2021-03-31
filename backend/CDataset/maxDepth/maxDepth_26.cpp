class Solution {
public:
	int dfs(TreeNode* root){
		if(not root) return 0;
		int left=dfs(root->left);
		int right=dfs(root->right);
		return max(left,right)+1;
	}
	int maxDepth(TreeNode* root) {
		return dfs(root);
	}
