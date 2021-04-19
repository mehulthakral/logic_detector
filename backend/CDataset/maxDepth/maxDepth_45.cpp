class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        int ltree = 0, rtree = 0;
        
        if (root == NULL) return 0;
        ltree = maxDepth(root->left);
        rtree = maxDepth(root->right);
        if (ltree < rtree) 
            ltree = rtree;;
            
        return ltree + 1;
    }
};
