class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> levels;
        level(root, 0, levels);
        return levels;
    }
private:
    void level(TreeNode* root, int l, vector<vector<int>>& levels) {
        if (!root) {
            return;
        }
        if (levels.size() <= l) {
            levels.push_back({});
        }
        levels[l].push_back(root -> val);
        level(root -> left, l + 1, levels);
        level(root -> right, l + 1, levels);
    }
};
