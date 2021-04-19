class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };void check(TreeNode* curnode)
{
	if(curnode == NULL)
		return ;
    check(curnode->left);
        s_arr.push_back(curnode->val);
    check(curnode->right);
    return ;
}

bool isValidBST(TreeNode *root) {
     if(root == NULL)
        return true;
    check(root);
    for(int i = 1 ; i < s_arr.size() ;i++)
    {
        if(s_arr[i] <= s_arr[i-1])
            return false;
    }
    return true;
}

vector<int> s_arr;
};