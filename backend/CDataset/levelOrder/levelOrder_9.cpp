class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int N = q.size();
            for(int i=0;i<N;i++){
                TreeNode* top = q.front();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                level.push_back(top->val);
                q.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};
