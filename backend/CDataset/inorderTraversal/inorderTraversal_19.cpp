class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> vec;
        inorderTraversal (root, vec);
        return vec;  
    }
    
   void inorderTraversal(TreeNode* root , vector <int> &vec){
       if (root != NULL){
           inorderTraversal (root->left , vec);
           vec.push_back(root->val);
           inorderTraversal (root->right , vec);
       }
   }
    
};
