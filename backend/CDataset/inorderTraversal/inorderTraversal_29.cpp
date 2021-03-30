class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> inOrder;
        TreeNode* temp;
        vector<int> ret;
        if(root)
        {
            inOrder.push(root);
            while(!inOrder.empty())
            {
                temp=inOrder.top();
                if(temp->left)
                {
                    inOrder.push(temp->left);
                    temp->left=NULL;
                }
                else
                {
                    inOrder.pop();
                    ret.push_back(temp->val);
                    if(temp->right)
                    {
                        inOrder.push(temp->right);
                        temp->right=NULL;
                    }
                }
            }
        }
        return ret;
    }
};
