class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int i;
        while(!q.empty()) {
            vector<int> curLevel;
            int b = q.size();
            for( i = 0; i < b; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(curLevel);
        }
        return res;
    }
};
