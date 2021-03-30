class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // base case
        if (root == nullptr) {
            return true;
        }
        
        // visit the left sub-tree
        if (!isValidBST(root->left)) {
            return false;
        }
        
        // an in-order traversal of a valid binary search tree
        // will always process nodes in-order. if the pervious
        // node is larger than current value, this condition
        // fails and we can assume that the tree isn't a valid BST
        if (previous && previous->val >= root->val) {
            return false;
        }
        
        // set the previous node to the current node
        previous = root;
        
        // visit the right sub-tree
        return isValidBST(root->right);
    }
private:
    TreeNode* previous = nullptr;
};
