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
    int maxPathSum(TreeNode* root) {
        int currentSum = INT_MIN;
        int maxSum = INT_MIN;
        
        go(root,currentSum,maxSum);
        
        return maxSum;
    }
    
    int go(TreeNode* root,int &currentSum,int &maxSum){
        
        int l = 0;
        int r = 0;
        
        if (root->left != nullptr){
            l = go(root->left,currentSum,maxSum);
        }
        if (root->right != nullptr){
            r = go(root->right,currentSum,maxSum);
        }
        
        currentSum = max(l + root->val,r + root->val);
        currentSum = max(currentSum,root->val);
        maxSum = max(max(maxSum,currentSum),l + r + root->val);
       
        
        return currentSum;
    }
};
