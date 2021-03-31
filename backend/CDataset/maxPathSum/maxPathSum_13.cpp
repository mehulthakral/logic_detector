int f;
int Function(TreeNode* root){
if(root==NULL){
return 0;
}
int a=Function(root->left);
int b=Function(root->right);
int k=max(a,b);
k=max(k,0);
k=k+root->val;
f=max(f,k);
f=max(f,root->val+a+b);

    return k;
    
}

int maxPathSum(TreeNode* root) {
    f=INT_MIN;
    Function(root);
    
    return f;
    
}