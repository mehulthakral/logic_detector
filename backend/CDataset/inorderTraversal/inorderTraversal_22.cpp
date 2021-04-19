class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        stack<TreeNode*> s;
        if(root == NULL)
            return out;
        while(root!=NULL || !s.empty())
        {
            while(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            out.push_back(root->val);
            root = root->right;
        }
        return out;
    }
};
