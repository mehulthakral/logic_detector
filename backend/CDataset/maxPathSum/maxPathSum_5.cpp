class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findMaxPath(root,ans);
        return ans;
    }
    int findMaxPath(TreeNode* root,int& ans){
        if(!root){
            return 0;
        }
        //JUST TO REMEMBER : to neutralise the -ve value returned from findMaxPath() bcz if we do not do that the ans value will be affected
        int fromLeft=max(0,findMaxPath(root->left,ans));
        int fromRight=max(0,findMaxPath(root->right,ans));
		 //IMPORTANT
        ans=max(ans,fromLeft+fromRight+root->val);
        return max(fromLeft,fromRight)+root->val;
        
    }
};
