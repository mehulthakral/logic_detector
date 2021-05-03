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
        
        if(!root) {
            return {};
        }
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            
            while(n>0) {
                TreeNode* t = q.front(); q.pop();
                
                tmp.push_back(t->val);
                
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
                
                n--;
            }
            ans.push_back(tmp);
        }
        
        return ans;
        
    }
};
