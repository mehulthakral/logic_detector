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
    vector<int> ret;
    stack<TreeNode *> s;
    for (TreeNode *n = root; n || !s.empty(); n = n->right) {
      for (; n; n = n->left) s.push(n);
      n = s.top(); s.pop();
      ret.push_back(n->val);
    }
    return ret;
  }
};