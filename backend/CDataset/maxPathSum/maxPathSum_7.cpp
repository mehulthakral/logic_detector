class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        helper(root,sum);
        return sum;
    }
    int helper(TreeNode* root, int &sum)
    {
        if(root==NULL)
            return 0;
        int l=max(0,helper(root->left,sum));
        int r=max(0,helper(root->right,sum));
        
        sum=max(sum, root->val+l+r);
        return (root->val +max(l,r));
    }
};
