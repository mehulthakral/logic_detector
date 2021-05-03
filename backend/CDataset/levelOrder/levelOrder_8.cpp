class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(root==NULL){
            return levels;
        }
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int curr_size= q.size();
            for(int i=0; i< curr_size; ++i){
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);
                if(front->left!=NULL) q.push(front->left);
                if(front->right!=NULL) q.push(front->right);
            }
            levels.push_back(level);
            level.clear();
        }
        return levels;
    }
};
