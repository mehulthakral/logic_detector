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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        int iL = maxDepth(root->left);
        int iR = maxDepth(root->right);
        
        if (iL > iR){
            return ++iL;
        }
        return ++iR;
    }
};
