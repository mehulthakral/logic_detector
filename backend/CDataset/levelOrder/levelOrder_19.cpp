class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    void helper(TreeNode*root,vector<vector<int>>&result,int level){
        if(root){
            if(level==result.size()){result.push_back({root->val});}
            else{result[level].push_back(root->val);}
            helper(root->left,result,level+1);
            helper(root->right,result,level+1);
        }
    }
    vector<vector<int>>levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        int level=0;
        helper(root,result,0);
        return result;
    }
};
