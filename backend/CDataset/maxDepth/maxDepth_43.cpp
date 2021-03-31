int maxDepth(TreeNode* root) {
    int num = 0;
    if(root){  
        num = 1; 
        int left = 0;
        int right = 0;
        left = maxDepth(root->left);  
        right = maxDepth(root->right);  
        if(left > right)
            num += left;
        else
            num += right;
    }
    return num;
}