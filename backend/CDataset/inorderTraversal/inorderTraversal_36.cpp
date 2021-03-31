class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> visit;
        TreeNode* cur = root;
        while(cur || !visit.empty()) {
            if(cur) {
                visit.push(cur);
                cur = cur->left;
            }else {
                cur = visit.top();
                visit.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
