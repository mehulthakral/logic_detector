class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> ans;
        if(root)
            nodes.push(root);
        while(!nodes.empty()){
            int size=nodes.size();
            vector<int> temp;
            
            for(int i=0;i<size;i++){
               TreeNode* curr=nodes.front(); 
                temp.push_back(curr->val);
                if(curr->left)
                    nodes.push(curr->left);
                if(curr->right)
                    nodes.push(curr->right);
                nodes.pop();
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};
