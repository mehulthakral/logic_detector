class Solution {
private:
    long preVal {LONG_MIN};
    
    bool DFS(TreeNode *u) {
        if (!u) return true;
        
        if (!DFS(u->left)) return false;
        if (u->val <= preVal) return false;
        else preVal = u->val;
        if (!DFS(u->right)) return false;
        return true;
    }
public:
		bool isValidBST(TreeNode* root) {
        return DFS(root);
    }
};
