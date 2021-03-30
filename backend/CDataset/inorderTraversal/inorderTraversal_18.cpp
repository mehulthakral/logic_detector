class Solution {
    
    private:
    void inOrder(TreeNode* root, vector<int> &vec){
        
        if(root != NULL){
            inOrder(root->left, vec);
            vec.push_back(root->val);
            inOrder(root->right, vec);
        }
        
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        inOrder(root, ans);
        
        return ans;
    }
};
