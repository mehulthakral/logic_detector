class Solution {
public:
int flag = 1;
void valid(TreeNode *cur,long long int min,long long int max) {
	if (!flag)
		return;
	if (cur == NULL)
		return;

	if (cur->val > min && cur->val < max)
	{
		valid(cur->left, min, cur->val);
		valid(cur->right, cur->val, max);
	}
	else
		flag = 0;
}
bool isValidBST(TreeNode* root) {		
	valid(root,(long long int) INT_MIN-1,(long long int) INT_MAX+1);
	if (!flag)
		return 0;
	return 1;
	
}
 };