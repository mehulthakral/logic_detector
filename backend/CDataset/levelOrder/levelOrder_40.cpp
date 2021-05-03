class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;

        queue<TreeNode* > q;
        q.push(root);
        int cnt_prev = 1, cnt_pres = 0;
        
        while (!q.empty()){
            vector<int> level;
            while(cnt_prev > 0){
                TreeNode* cur = q.front();
                level.push_back(cur->val);
                q.pop();
                cnt_prev--;
                
                if (cur->left){
                    q.push(cur->left);
                    cnt_pres++;
                }
                if(cur->right){
                    q.push(cur->right);
                    cnt_pres++;
                }
                
            }
            cnt_prev = cnt_pres;
            cnt_pres = 0;
            res.push_back(level);
            
        }
        return res;
            
    }
};
