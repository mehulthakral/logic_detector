/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if( !root )
            return NULL;
        return 1 + max(height(root->left),height(root->right));
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
            vector< vector<int > > res;
            if( !root )
                return res;
            int h = height(root);
            vector<vector<TreeNode* > > dp;
            dp.push_back({root});
            res.push_back({root->val});
            for(int i=0;i<=h;i++){
                vector<TreeNode*> t;
                vector<int> r;
                for(int j=0;j<dp[i].size();j++){
                    if(dp[i][j]->left){
                        t.push_back(dp[i][j]->left);
                        r.push_back(dp[i][j]->left->val);
                    }
                    if(dp[i][j]->right){
                        t.push_back(dp[i][j]->right);
                        r.push_back(dp[i][j]->right->val);
                    }
                }
                    dp.push_back(t);
                    if(r.size())
                        res.push_back(r);
         }
            
        return res;
    }
};
