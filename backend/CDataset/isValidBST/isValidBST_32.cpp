class Solution {
public:
	class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool checkRange(TreeNode* node, long long l, long long h){
        if(node == nullptr) return true;
        if(node->val <= l || node->val >= h) return false;
        return checkRange(node->left, l, node->val) && checkRange(node->right, node->val, h);
    }
    
    bool isValidBST(TreeNode* root) {
        return checkRange(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
};