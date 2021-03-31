    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> tstack;
        vector<int> vals;
        if(root==NULL)  return vals;
        tstack.push(root);
        while(!tstack.empty()) {
            while(root) {
                if(tstack.top()!=root)  tstack.push(root);
                root=root->left;
            }
            root=tstack.top();
            vals.push_back(root->val);
            tstack.pop();
            if(root->right) {
                tstack.push(root->right);
            }
            root=root->right;
        }
        return vals;
    }