class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    stack <TreeNode * > s;
    void mypush(TreeNode * node) // pushes a node and all its left members onto stack
    {
        while(node)
        {
            s.push(node);
            node = node->left;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res; 
        mypush(root);
        while(!s.empty())
        {
            TreeNode * p = s.top();
            res.push_back(p->val);
            s.pop();
            mypush(p->right);
        }
        return res;
    }
};
