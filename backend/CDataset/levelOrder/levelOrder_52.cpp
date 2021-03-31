vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    deque<TreeNode*> q;
    
    if (root)   q.push_front(root);        
    while (q.size()) {
        ret.resize(ret.size() + 1);
        int og_size = q.size(); 
            
        for (int i = 0, og_size = q.size(); i != og_size; i++)  {
            auto node = q.front();
            ret.back().push_back(node->val);
    
            if (node->left)     q.push_back(node->left);
            if (node->right)    q.push_back(node->right);   
            q.pop_front();
        }
    }
    return ret;
}
