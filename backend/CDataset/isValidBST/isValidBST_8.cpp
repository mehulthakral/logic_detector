class Solution {
public:

void inorder(TreeNode* root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}

bool isValidBST(TreeNode* root) {
    
    if(root==NULL)
    {
        return true;
    }
    vector<int>v;
    inorder(root,v);
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>=v[i+1])
        {
            return false;
            break;
        }
    }
    return true;
}
};