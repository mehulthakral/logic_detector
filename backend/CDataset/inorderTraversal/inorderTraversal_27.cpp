class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        make(root);
        return ans;
        
    }
    void make(TreeNode* root){
        if(root==NULL){
            return;
        }
        make(root->left);
        ans.push_back(root->val);
        make(root->right);
        return;
    }
};
