 vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            vector<int> inter;
            vector<vector<int>> result;
            while(q.size()!=NULL)
            {
               int count=q.size();
                while(count>0)
                {   TreeNode* curr=q.front();
                    q.pop();
                    inter.push_back(curr->val);
                    if(curr->left!=NULL)
                        q.push(curr->left);
                    if(curr->right!=NULL)
                        q.push(curr->right);
                    count--;
                }  
                result.push_back(inter);
                inter={};
            }
             return result;
         }
