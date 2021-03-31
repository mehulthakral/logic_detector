    void Traverse(TreeNode* root, vector<int>& res){
        if(root != NULL){
            Traverse(root->left, res);
            res.push_back(root->val);
            Traverse(root->right, res);
        }
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        Traverse(root, res);
        return res;
    }
