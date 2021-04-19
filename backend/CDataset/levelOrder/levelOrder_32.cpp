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
        if (!root) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> node;
        q.push(make_pair(root,0));
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (res.size() <= node.second) res.push_back({});
            res[node.second].push_back(node.first->val);
            
            if (node.first->left) q.push(make_pair(node.first->left,node.second+1));
            if (node.first->right) q.push(make_pair(node.first->right, node.second+1));
        }
        return res;
    }
};