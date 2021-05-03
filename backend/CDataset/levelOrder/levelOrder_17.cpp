class Solution {
public:
    #include<vector>

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>temparr;
        while(!q.empty()) {
            // n is the number of nodes in the current level
            int n = q.size();
            for (int i = 0; i<n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                temparr.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            res.push_back(temparr);
            temparr.clear();
        }
        return res;
    }
};