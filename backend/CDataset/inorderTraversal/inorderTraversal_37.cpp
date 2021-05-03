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
        TreeNode* cur = root;
        while(cur) {
            if(!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while(pred->right && pred->right != cur) pred = pred->right;
                if(!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
