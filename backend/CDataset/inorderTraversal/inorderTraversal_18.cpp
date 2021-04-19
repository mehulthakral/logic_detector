class Solution {

public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        inOrder(root, ans);
        
        return ans;
    }    
    private:
    void inOrder(TreeNode* root, vector<int> &vec){
        
        if(root != NULL){
            inOrder(root->left, vec);
            vec.push_back(root->val);
            inOrder(root->right, vec);
        }
        
    }
    
};
