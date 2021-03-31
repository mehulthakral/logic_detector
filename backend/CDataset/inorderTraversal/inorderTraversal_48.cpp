vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> stack;
        vector<int> vals;
        while(!stack.empty() or root) {
            while(root) {
                stack.push(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            vals.push_back(root->val);
            root=root->right;
        }
        return vals;
    }