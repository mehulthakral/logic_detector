class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        TreeNode *temp = NULL;
        int curLevelCount = 0;
        if (root == NULL) return ret;
        
        queue<TreeNode *>q;
        q.push(root);
        
        while (!q.empty())
        {
            curLevelCount = q.size();
            vector<int> level;
            while (curLevelCount--)
            {
                temp = q.front();
                level.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
                q.pop();
            }
            ret.push_back(level);
        }
        
        return ret;
    }
};