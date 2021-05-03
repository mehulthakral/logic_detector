class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
if (root == NULL)
        return 0;
    
 return max(maxDepth(root->left), maxDepth(root->right)) + 1;        
}
};