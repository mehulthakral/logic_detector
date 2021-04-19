
class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        int maxDepth=0;
        stack<TreeNode *> nodes;
        TreeNode* ptr;
        if(root)
        {
            root->val=1;
            nodes.push(root);
            while(!nodes.empty())
            {
                ptr=nodes.top();
                if(ptr->left && ptr->right)
                {
                    if(ptr->val==-1)
                    {
                        nodes.pop();
                        nodes.push(ptr->right);
                    }
                    else
                    {
                        ptr->left->val=ptr->val+1;
                        ptr->right->val=ptr->val+1;
                        ptr->val=-1;
                        nodes.push(ptr->left);
                    }
                }
                else if(ptr->left)
                {
                    if(ptr->val==-1)
                    {
                        nodes.pop();
                    }
                    else
                    {
                        ptr->left->val=ptr->val+1;
                        nodes.push(ptr->left);
                        ptr->val=-1;
                    }
                }
                else if(ptr->right)
                {
                    if(ptr->val==-1)
                    {
                        nodes.pop();
                    }
                    else
                    {
                        ptr->right->val=ptr->val+1;
                        nodes.push(ptr->right);
                        ptr->val=-1;
                    }
                }
                else
                {
                    if(ptr->val>maxDepth)
                    {
                        maxDepth=ptr->val;
                    }
                    nodes.pop();
                }
            }
        }
        return maxDepth;
    }
};
