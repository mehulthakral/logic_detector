class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

   vector<vector<int>> ans;
    queue<TreeNode*> q1;
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return ans;
         int k;
         auto p=root;
         q1.push(p);
         TreeNode* t;
        
        while(q1.size())
        {   
            k=q1.size();vector<int> ca;
            while(k--)
            {
                 t=q1.front();q1.pop();
                 if(t->left)  q1.push(t->left);
                 if(t->right) q1.push(t->right);
                 ca.push_back(t->val); 
                           
            }
            ans.push_back(ca);
            }
            return ans;       
        }
};