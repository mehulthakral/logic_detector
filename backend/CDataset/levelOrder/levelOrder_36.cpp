class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if (!root) return rst;
        
        queue<TreeNode*> q;
        queue<TreeNode*> nextq;
        vector<int> curlevel;
        
        q.push(root);
        while (not q.empty()) {
            // get the current node
            TreeNode* cur = q.front();
            q.pop();
            // process the node
            curlevel.push_back(cur->val);
            if (cur->left) nextq.push(cur->left);
            if (cur->right) nextq.push(cur->right);
            // if all nodes in the current level are processed, move to next level
            if (q.empty()) {
                rst.push_back(move(curlevel));
                q.swap(nextq);
            }
        }
        return rst;
    }
};
