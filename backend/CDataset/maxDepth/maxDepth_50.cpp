class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            depth++;
            int n = level.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front();
                level.pop();
                if (node -> left) level.push(node -> left);
                if (node -> right) level.push(node -> right);
            }
        }
        return depth; 
    } 
};