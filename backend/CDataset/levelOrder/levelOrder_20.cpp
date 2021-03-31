class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>m;
        vector<vector<int>>res;
        if(!root)
            return res;
        int x;
        TreeNode* temp;
        q.push({root,0});
        
        while(!q.empty())
        {
            temp=q.front().first;
            x=q.front().second;
            m[x].push_back(temp->val);
            q.pop();
            if(temp->left)
                q.push({temp->left,x+1});
            if(temp->right)
                q.push({temp->right,x+1});
        }
        
        for(auto r:m)
        {
            res.push_back(r.second);
        }
        
        return res;
        
    }
};
