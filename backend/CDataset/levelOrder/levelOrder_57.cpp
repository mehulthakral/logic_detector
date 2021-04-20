class Solution {
public:
    #include<vector>

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> ret;
	int qsize = 0;
	if (!root) return ret;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		vector<int> subret;
		qsize = q.size();
		while (qsize--)
		{
			TreeNode* tmp = q.front();
			q.pop();
			subret.push_back(tmp->val);
			if (tmp->left != NULL) q.push(tmp->left);
			if (tmp->right != NULL) q.push(tmp->right);
		}
		ret.push_back(subret);
}
return ret;
}
};