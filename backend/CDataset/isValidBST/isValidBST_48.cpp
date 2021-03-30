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
    bool isValidBST(TreeNode* root) {
        bool result = true;
        vector<int> v;
        this->inOrderTraverse(root, v);
        for (size_t i = 0; i < v.size(); ++i) {
            if (i + 1 < v.size()) {
                if (v[i + 1] <= v[i]) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
private:
    void inOrderTraverse(TreeNode* root, vector<int>& v) {
        if (root) {
            inOrderTraverse(root->left, v);
            v.push_back(root->val);
            inOrderTraverse(root->right, v);
        }
    }
};