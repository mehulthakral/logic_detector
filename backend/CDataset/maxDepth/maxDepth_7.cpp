class Solution {
public:
    int maxDepth(TreeNode* root) {
       return !root?0:max(maxDepth(root -> right),maxDepth(root -> left))+1; 
    }
};
