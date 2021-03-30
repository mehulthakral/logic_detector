class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        deque<TreeNode*>cur;
        deque<TreeNode*>next;
        cur.push_back(root);
        int level = 0;
        res.push_back(vector<int>());
        while(!cur.empty()){
            TreeNode* node = cur.front();
            cur.pop_front();
            if(node->left) next.push_back(node->left);
            if(node->right) next.push_back(node->right);
            res[level].push_back(node->val);
            if(cur.empty() && !next.empty()){
                res.push_back(vector<int>());
                level++;
                swap(cur, next);
            }
        }
        return res;
    }
};
