inline void f75(TreeNode* root,double left,double right,bool& flag){
	if(flag==false) return;
	if(root->val<right && root->val>left){
		if(root->left) f75(root->left,left,root->val,flag);
		if(root->right) f75(root->right,root->val,right,flag);
	}else
		flag=false;
	return;
}
bool isValidBST(TreeNode* root){
	if(root==NULL) return true;
	bool flag=true;
	double min=INT_MIN;
	min--;
	double max=INT_MAX;
	max++;
	f75(root,min,max,flag);
	return flag;
}