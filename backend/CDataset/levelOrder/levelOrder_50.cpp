class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root)
        return ans;
    queue<TreeNode*> q;
    q.push(root);

    vector<int> tmp;
    while(!q.empty()){
        int len = q.size();
        for(int i=0;i<len;i++){
            auto x = q.front();
            q.pop();
            tmp.push_back(x->val);
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }

        ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
    }
};
