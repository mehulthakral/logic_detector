class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	recur_levelOrder(result, root, 0);
	return result;
}

void recur_levelOrder(vector<vector<int>> &result, TreeNode *root, int level)
{
	if (!root)
	{
    	return;
    }
    if ((level+1) > result.size())
    {
	    result.push_back(vector<int> {});
    }
    result[level].push_back(root->val);
    recur_levelOrder(result, root->left, level+1);
    recur_levelOrder(result, root->right, level+1);
}
};