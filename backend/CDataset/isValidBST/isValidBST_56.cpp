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
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int ok = true, first = true;
    bool isValidBST(TreeNode* root) {
        int prev;
        travel(root, prev);
        return ok;
    }
    
    void travel(TreeNode *root, int &prev) {
        if (!(ok && root)) return;
        if (root->left) travel(root->left, prev);
        int mid = root->val;
        if (!first) {
            if (mid <= prev) ok = false;
            prev = mid;
        } else { 
            first = false; 
            prev = mid; 
        }
        if (root->right) travel(root->right, prev);
    }
};