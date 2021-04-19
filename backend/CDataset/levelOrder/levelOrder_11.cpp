class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    void helper(TreeNode* root,vector<vector<int>>&ans,int level){
        if(root==NULL)return;
        if(level>=ans.size()){//this means this level has not been parsed before and is therefore absent in the ans variable
            ans.push_back(vector<int>{root->val});
        }
        else{//as level is already present, simply push to that level's vector
            ans[level].push_back(root->val);   
        }
        helper(root->left,ans,level+1);
        helper(root->right,ans,level+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        helper(root,ans,0);
        return ans;
    }
};