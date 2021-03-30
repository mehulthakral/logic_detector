void magic(TreeNode* node,int cd,int &md)
    {
        if(cd>md)
            md=cd;
        if(node->left)
            magic(node->left,cd+1,md);
        if(node->right)
            magic(node->right,cd+1,md);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxdepth=1;
        int currentdepth=1;
        magic(root,currentdepth,maxdepth);
        return maxdepth;
    }