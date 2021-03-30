pair<bool, pair<int,int>> dfs(TreeNode* root){
    
    pair<bool, pair<int,int>> my_pair = {true, {root->val, root->val}};
    
    if(root->left){
        
        auto l = dfs(root->left);
        
        my_pair.first = my_pair.first && l.first;
        
        if(l.second.second >= root->val)                
            my_pair.first = false;
        
        my_pair.second.first = min(my_pair.second.first, l.second.first);
        my_pair.second.second = max(my_pair.second.second, l.second.second);
    }
    
    if(root->right){
        
        auto r = dfs(root->right);
        
        my_pair.first = my_pair.first && r.first;
        
        if(r.second.first <= root->val)                
            my_pair.first = false;
        
        my_pair.second.first = min(my_pair.second.first, r.second.first);
        my_pair.second.second = max(my_pair.second.second, r.second.second);
    }
    
    return my_pair;        
}

bool isValidBST(TreeNode* root) {
    
    if(!root)
        return true;

    return dfs(root).first;
}