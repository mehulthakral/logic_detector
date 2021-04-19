class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int solve(TreeNode* root,int &res){
        if(NULL == root)
            return 0;
        int left_val=solve(root->left,res);
        int right_val=solve(root->right,res);
        int curr_max=max(max(left_val,right_val)+root->val,root->val);
        res=max(res,curr_max);
        res=max(res,max(curr_max,left_val+right_val+root->val));
        return curr_max;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};
