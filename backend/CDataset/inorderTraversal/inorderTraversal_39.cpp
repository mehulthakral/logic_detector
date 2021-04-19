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
       if(root == NULL) return ans;
       stack<TreeNode*> st;
      while(root != NULL) {
          st.push(root);
          root = root->left;
      }
       while(st.size() != 0) {
           root = st.top();
           st.pop();
           ans.push_back(root->val);
           if(root->right != NULL) {
               root = root->right;
               while(root != NULL) {
                   st.push(root);
                   root = root->left;
               }
           }
       }
       return ans;
    }
};