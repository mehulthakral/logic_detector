class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        std::stack<std::pair<TreeNode*, bool>> in_process;
        in_process.emplace(root, false);

        while (!in_process.empty()) {
            auto [node, is_processed] = in_process.top();
            in_process.pop();
			
            if (node) {
                if (is_processed) {
                    result.push_back(node->val);
                } else {
                    in_process.emplace(node->right, false);
                    in_process.emplace(node, true);
                    in_process.emplace(node->left, false);
                }
            }
        }

        return result;
    }
};
