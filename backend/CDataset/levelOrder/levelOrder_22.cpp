/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty()==false)
        {
            vector<int>curr_res;
            int c=q.size();
            for(int i=0;i<c;i++)
            {
                TreeNode* t=q.front();
                curr_res.push_back(t->val);
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            res.push_back(curr_res);
        }
        return res;
    }
};