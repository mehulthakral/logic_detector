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
        
        TreeNode* current=root;
        
        while(current!=NULL)
        {
            if(current->left==NULL)
            {
                v.push_back(current->val);
                current=current->right;
            }
            else{
                TreeNode* preNode=current->left;
                
                while(preNode->right!=NULL && preNode->right!=current)
                    preNode=preNode->right;
                
                if(preNode->right==current)
                {
                    v.push_back(current->val);
                    preNode->right=NULL;
                    current=current->right;
                }
                else
                {
                    preNode->right=current;
                    current=current->left;
                }
            }
        }
        return v;
    }
};
