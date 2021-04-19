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
        vector<int> v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s;
        TreeNode* current=root;
        while(!s.empty() || current!=NULL)
        {
            while(current!=NULL)
            {
                s.push(current);
                current=current->left;
            }
            current=s.top();
            s.pop();
            v.push_back(current->val);
            current=current->right;
        }
        return v;
    }
};
