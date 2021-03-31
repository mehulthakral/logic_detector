class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            vector<int> vec;
            bool flag = false;
            while(true){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp == NULL){
                    break;
                }
                vec.push_back(tmp->val);
                if(tmp->left != NULL){
                    q.push(tmp->left);
                    flag = true;
                }
                if(tmp->right != NULL){
                    q.push(tmp->right);
                    flag = true;
                }
            }
            ans.push_back(vec);
            if(flag){
                q.push(NULL);
            }
        }
        return ans;
    }
};