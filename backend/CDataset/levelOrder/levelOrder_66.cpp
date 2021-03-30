class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        
          
          vector<vector<int>>ans{};
          if(!root) return ans;
        vector<int> row;
        vector<pair<TreeNode*,int>> vec; // to store the node and its level
        int level=0;
        vec.push_back({root,0});
        int size =1;
        int i=0;
        int j=0;
        while(i<size)// must take indices because iterators may become invalid upon adding to the vector
        {
            while(vec[i].second==level)
            {
                row.push_back(vec[i].first->val);
                if(vec[i].first->left)   {vec.push_back({vec[i].first->left, level+1});  size++;  }
                if(vec[i].first->right) {vec.push_back({vec[i].first->right,level+1});  size++;  }
                i++;
            }
            level++;
            ans.push_back(row);
            row.clear();
        }
        
        return ans;
    }
};
