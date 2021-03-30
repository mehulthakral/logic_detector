class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> levels;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            levels.push_back({});
            for (int i = 0, n = todo.size(); i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                levels.back().push_back(node -> val);
                if (node -> left) {
                    todo.push(node -> left);
                }
                if (node -> right) {
                    todo.push(node -> right);
                }
            }
        }
        return levels;
    }
};
