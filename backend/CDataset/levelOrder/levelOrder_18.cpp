class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> que{root};
        vector<int> temp;
        while(!que.empty()){
            int n = que.size();
            for(int i=0;i<n;++i){
                TreeNode* cur = que.front();
                temp.push_back(cur->val);
                que.pop_front();
                if(cur->left) que.push_back(cur->left);
                if(cur->right) que.push_back(cur->right);
            }
            ret.push_back(temp);
            temp.clear();
        }
        return ret;
    }
};
