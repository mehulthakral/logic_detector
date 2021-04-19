class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root, long int minValue = numeric_limits<long int>::min(), long int maxValue = numeric_limits<long int>::max()) 
    {
        return !root ? true : minValue < root->val && maxValue > root->val ? 
			isValidBST(root->left, minValue, root->val) && isValidBST(root->right, root->val, maxValue) : false;
    }
};
/*
If we reach a nullptr, return true since we haven't been invalidated yet. 
On the way down make sure that the current root's value is within our bounds. 
If it isn't return false. If it is, make sure that its left and 
right children are within the bounds. The left child's lower bound is the smallest long number. 
Its upper bound is the current node's value, as left child must be within lower bound but less
than the current root.
The same logic applies for the right node but in reverse.
*/
