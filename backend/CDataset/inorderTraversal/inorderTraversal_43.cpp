class Solution {
public: 
//     Iterative
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};