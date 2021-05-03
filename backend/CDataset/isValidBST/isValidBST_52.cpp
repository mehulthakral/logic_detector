class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
    	int max, min;
    	return isValidBST_c(root, &max, &min);
    }
private:
	bool isValidBST_c(TreeNode* root, int* max, int* min){
		if (root == nullptr)
			return true;

		int l_max, l_min;
		int r_max, r_min;
		bool b_left = isValidBST_c(root->left, &l_max, &l_min);
		bool b_right = isValidBST_c(root->right, &r_max, &r_min);

		if(b_left && b_right) {
			*max = root->right == nullptr ? root->val : r_max;
			*min = root->left == nullptr ? root->val : l_min;

			if (root->left != nullptr && root->val <= l_max)
				return false;
			if (root->right != nullptr && root->val >= r_min)
				return false;

			return true;
		}
		return false;
	}
};