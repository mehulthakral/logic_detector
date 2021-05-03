/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int speedup=[](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
	int maxi=INT_MIN;

	int maxSum(TreeNode* root) {
		if(!root) return 0;
		if(!root->left && !root->right) {
			maxi = max(maxi,root->val);
			return root->val;
		} 

		int v1 = maxSum(root->left);
		int v2 = maxSum(root->right);
		int tmp = max(root->val, max(v1, v2)+root->val);
		maxi = max(maxi, max( (v1+v2+root->val), tmp));
		return tmp;
	}

	int maxPathSum(TreeNode* root) {
		maxSum(root);
		return maxi;
	}
};