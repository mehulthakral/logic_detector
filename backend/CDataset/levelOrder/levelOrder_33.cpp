class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int qSize = q.size(); // Only difference with P104 is that we need to fix the size of queue in each epoch
            for (int i = 0; i < qSize; i++) {
                TreeNode* p = q.front();
                q.pop();
                tmp.push_back(p->val);
                if (p->left != NULL) 
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
