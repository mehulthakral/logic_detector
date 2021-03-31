void traverse(TreeNode* node, vector<vector<int>> &result, int level){
        if(!node) return;
        if (result.size() < level+1)
    		result.push_back(vector<int>());
        result[level++].push_back(node->val);
        traverse(node->left, result, level);
        traverse(node->right, result, level);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result, 0);
        return result;
    }