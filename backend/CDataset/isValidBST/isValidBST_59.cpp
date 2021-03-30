class Solution {
public:
bool isValidBST(TreeNode* root){
	if(root)
	{
		bool isOk = true;
		
		if(root->left)
			isOk = recursiveCheck(root->left, numeric_limits<long int>::min(), root->val);

		if(isOk)
		{
			if(root->right)
				return recursiveCheck(root->right, root->val, numeric_limits<long int>::max());
			
			return isOk;
		}
		else
			return false;
	}
	else
		return true;
}

bool recursiveCheck(TreeNode * ctnode, long int lowerBound, long int upperBound)
{
	if(!ctnode) return true;
	else if(ctnode->val >= upperBound || ctnode->val <= lowerBound)
		return false;
	else
	{
		bool isOk = true;
		if(ctnode->left)
		{
			isOk = recursiveCheck(ctnode->left, lowerBound, ctnode->val);
		}

		if(isOk)
		{
			if(ctnode->right)
				return recursiveCheck(ctnode->right, ctnode->val, upperBound);
			else
				return true;
		}
		else
			return false;
	}
}
};