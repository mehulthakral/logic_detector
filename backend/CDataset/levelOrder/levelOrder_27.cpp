/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        vector<TreeNode*> currLevel{};
        if (root) currLevel.push_back(root);
        while (currLevel.size()) {
            vector<TreeNode*> nextLevel{};
            vector<int> temp{};
            for (TreeNode* n: currLevel) {
                temp.push_back(n->val);
                if (n->left) nextLevel.push_back(n->left);
                if (n->right) nextLevel.push_back(n->right);
            }
            currLevel = nextLevel;
            res.push_back(temp);
        }
        return res;
    }
};
