class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return {}; }
        vector<int> row;
        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;

            while (!q.empty()) {
            if (q.front()->left) { q.push(q.front()->left); }
            if (q.front()->right) { q.push(q.front()->right); }
            row.push_back(q.front()->val), q.pop();
            if (--count == 0) {
                result.emplace_back(row), row.clear();
                count = q.size();
            }
        }
        return result;
    }
};