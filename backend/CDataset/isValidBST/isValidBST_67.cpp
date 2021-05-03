class Solution {
    public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    	bool isValidBST(TreeNode* root, int upper, bool hasupper, int lower, bool haslower) {
    		if ((root->left != NULL && (root->left->val >= root->val || (haslower &&root->left->val <= lower))) ||
    			(root->right != NULL && (root->right->val <= root->val ||( hasupper && root->right->val >= upper))) ||
    			(root->left != NULL && !isValidBST(root->left, root->val, true, lower, haslower)) ||
    			(root->right != NULL && !isValidBST(root->right, upper, hasupper, root->val, true))
    			)
    		{
    			return false;
    		}
    		return true;
    	}
    	bool isValidBST(TreeNode* root) {
    	    if (root == NULL) return true;
    		return isValidBST(root, INT_MAX, false, INT_MIN, false);
    	}
    };