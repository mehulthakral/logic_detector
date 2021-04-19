class Solution {
public:
    #include<vector>

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode*> Q;
        vector<vector<int>> res;
        if(root == nullptr) return res;
        Q.push(root);
        while(Q.size() != 0) {
            int size = Q.size();
            vector<int> v;
            for(int i = 0; i < size; i++) {
                 TreeNode* t = Q.front();
                 Q.pop();
                 v.push_back(t->val);
                if(t->left != nullptr) 
                    Q.push(t->left);
                if(t->right != nullptr)
                    Q.push(t->right);
            }
            res.push_back(v);
        }
        return res;
    }
};