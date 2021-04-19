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
        if(!root) return {};
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()) {
            while(curr) {
                 st.push(curr);
                 curr = curr->left;
            }
            curr = st.top();
            result.push_back(curr->val);
            st.pop();
            curr = curr->right;
        }
        return result;
    }
};
