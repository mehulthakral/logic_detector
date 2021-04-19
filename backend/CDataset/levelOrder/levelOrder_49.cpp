class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) const {
        if (root == nullptr) return {};
        vector<vector<int>> ret;
        vector<decltype(root)> current{root}, next;
        while (not current.empty()) {
            decltype(ret)::value_type vals;
            for (auto c : current) {
                vals.push_back(c->val);
                if (auto n = c->left; n != nullptr)
                    next.push_back(n);
                if (auto n = c->right; n != nullptr)
                    next.push_back(n);
            }
            current = move(next);
            ret.push_back(move(vals));
        }
        return ret;
    }
};
