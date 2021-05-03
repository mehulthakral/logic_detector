class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int max(int a, int b)
    {
        return a>b?a:b;
    }
    
    int maxDepth(TreeNode* root) {
       // base case
       if(root == NULL)
            return 0;
            
        return 1+ max(maxDepth(root->left), maxDepth(root->right));    
    }
};