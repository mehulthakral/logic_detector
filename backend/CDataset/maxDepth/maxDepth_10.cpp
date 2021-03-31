/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ldepth = maxDepth(root->left); //finds leftsubtree depth
        int rdepth = maxDepth(root->right); //finds right subtree depth
        return 1+max(rdepth,ldepth); // 1 is for root and maximum of left and right depth
    }
};
