/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <algorithm>
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
		    return 0;
	    }

	    return (1 + std::max(maxDepth(root->left), maxDepth(root->right)));
    }
};