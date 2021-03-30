class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        queue<TreeNode*> bq;
        if(root) bq.push(root);
        while(!bq.empty()){
            vector<int> level;
            int s = bq.size();
            while(s--){
                TreeNode* tn = bq.front();
                bq.pop();
                level.push_back(tn->val);
                if(tn->left) bq.push(tn->left);
                if(tn->right) bq.push(tn->right);
            }
            output.push_back(level);
        }
        return output;
    }
};
