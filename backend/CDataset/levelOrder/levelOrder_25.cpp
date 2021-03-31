class Solution {
public:
    int size(TreeNode* root){
        if(root==NULL) return 0;
        return size(root->left) + size(root->right) + 1;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        q.push(NULL);
        vector<int>inside;
        ans.push_back(inside);
        int count = size(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front==NULL) {
                if(count<=0) break;
                q.push(NULL);
                ++i;
                vector<int>inside;
                ans.push_back(inside);
                continue;
            }
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
            ans[i].push_back(front->val);
            --count;
        }
        return ans;
    }
};
