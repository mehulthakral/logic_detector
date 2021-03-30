class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results={};
        if(root==NULL){
            return results;
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(results.size()<top.first+1){results.resize(top.first+1, vector<int>{});}
            (results[top.first]).push_back(top.second->val);
            if(top.second->left!=NULL){
                q.push({top.first+1, top.second->left});
            } 
            if(top.second->right!=NULL){
                q.push({top.first+1, top.second->right});
            }
        }
        return results;
    }
};
