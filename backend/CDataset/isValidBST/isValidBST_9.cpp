class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
    	if (root == nullptr)
    		return true;

    	if(!isValidBST(root->left))
    		return false;

    	if (pre != nullptr && pre->val >= root->val)
    		return false;

    	pre = root;
    	return isValidBST(root->right);

    }
private:
	TreeNode* pre = nullptr;
};