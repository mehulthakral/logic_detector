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
    
    int ans=INT_MIN;
    int solve(TreeNode *trav){
        if(!trav)return 0;
        int sum=trav->val;

        int l_sum=solve(trav->left);
        int r_sum=solve(trav->right);
        
        l_sum=max(l_sum,0);
        r_sum=max(r_sum,0);
        
        ans =max(ans,l_sum+r_sum+sum);
        return max(l_sum,r_sum)+sum;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
