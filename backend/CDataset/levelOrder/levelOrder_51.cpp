class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        if (!root)
            return res;
        
        q.push(root);
        
        while (!q.empty()) {
            auto size = q.size();
            vector<int> v;
            
            for (auto i = 0; i < size; i++) {
                TreeNode *t = q.front();
                
                q.pop();
                v.push_back(t->val);
                
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res.push_back(v);
        }
        return res;
    }
};
