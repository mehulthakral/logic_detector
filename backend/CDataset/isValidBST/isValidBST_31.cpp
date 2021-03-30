	bool dfs(TreeNode* node, long long& res){
      if(node == nullptr) return true;
      if(!dfs(node->left, res)) return false;
      if(res >= node->val) return false;
      else res = node->val;
      if(!dfs(node->right, res)) return false;
      return true;
    }
    
    bool isValidBST(TreeNode* root) {
        long long res = numeric_limits<long long>::min();
        return dfs(root, res);
    }
