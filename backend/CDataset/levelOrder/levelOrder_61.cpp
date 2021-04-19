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
        vector<vector<int>> ans;
        int i = 0;
        if(root == NULL)
            return ans;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
            for(int j = 0, len = que.size(); j < len; j++)
            {
                TreeNode * temp = que.front();
                ans[i].push_back(temp->val);
                que.pop();
                if(!temp->left)     que.push(temp->left);
                if(!temp->right)    que.push(temp->right);
            }
            i++;
        }
        return ans;
    }
};