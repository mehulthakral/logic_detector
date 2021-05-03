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
        vector<int> ans;
        //insertNode(root,ans);
        stack<TreeNode*> nodes;
        // nodes.push(root);
        while(!nodes.empty() || root!=NULL){
            while(root!=NULL){
                //cout<<root->val<<endl;
                nodes.push(root);    
                root=root->left;
            }
            root=nodes.top();
            // cout<<root->val<<endl;
            ans.push_back(root->val);
            nodes.pop();
            root=root->right;
        }
        return ans;
    }
    
    
};
