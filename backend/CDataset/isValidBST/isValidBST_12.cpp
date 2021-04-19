class Solution {
public:
#include<vector>
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        vector<int> inorder;
        checkBST(root,inorder);
        int prev=inorder[0];
        for(int i=1;i<inorder.size();i++){
            if(prev>=inorder[i]){
                return false;
            }
            prev=inorder[i];
        }
        return true;
    }
    void checkBST(TreeNode* root,vector<int>& inorder){
        if(root==NULL)
            return ;
        checkBST(root->left,inorder);
        inorder.push_back(root->val);
        checkBST(root->right,inorder);
    }
};
