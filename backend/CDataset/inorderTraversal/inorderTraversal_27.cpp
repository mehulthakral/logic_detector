class Solution {
public:
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
