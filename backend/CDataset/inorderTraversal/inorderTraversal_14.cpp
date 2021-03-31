 class Solution {
 public:
     vector<int> inorderTraversal(TreeNode* root){ 
         if(root==NULL)
            return {};
         vector<int> vec;
         stack<TreeNode*> s;
         while(true){
             if(root!=NULL){
                s.push(root);
                root=root->left; 
             }
             else{
                 if(s.empty())
                     break;
                 root=s.top();
                 s.pop();
                 vec.push_back(root->val);
                 root=root->right;
             }
         }
         return vec;
     }
 };
