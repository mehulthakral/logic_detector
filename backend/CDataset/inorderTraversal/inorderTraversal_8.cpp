class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        
        TreeNode* curr = root;
        while(curr || !stk.empty()) {
            if(curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                result.push_back(stk.top()->val);
                curr = stk.top()->right;
                stk.pop();
            }
        }
        
        return result;
    }
    
};
