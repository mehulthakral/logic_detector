class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root == NULL)
            return v;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> vtemp;
            queue<TreeNode*> qtemp;
            while(!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                vtemp.push_back(temp->val);
                if(temp->left) qtemp.push(temp->left);
                if(temp->right) qtemp.push(temp->right);
            }
            v.push_back(vtemp);
            
            while(!qtemp.empty()) {
                q.push(qtemp.front());
                qtemp.pop();
            }
        }
        
        return v;
    }
};
