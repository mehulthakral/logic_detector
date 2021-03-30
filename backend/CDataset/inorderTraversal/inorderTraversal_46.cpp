class Solution {
public:
vector inorderTraversal(TreeNode* root) {

    vector<int>v;
    if(!root)
        return v;
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* top = s.top();
        if(top->left)
        {
            s.push(top->left);
            top->left=NULL;
        }
        else
        {
            v.push_back(top->val);
            s.pop();
            if(top->right)
                s.push(top->right);
        }
    }
    return v;
}
};