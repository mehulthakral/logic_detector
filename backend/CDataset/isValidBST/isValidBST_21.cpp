class Solution {
public:
#include<vector>
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool flag = true;
    vector<int> dfs(TreeNode * root)
    {
       if(!root) return {}; 
       vector<int> left = dfs(root -> left); 
       vector<int> right = dfs(root -> right);
       vector<int> merge;
       for(int i = 0 ; i < left.size();i++)
       {
           if(left[i] >= root-> val) flag = false; 
           merge.push_back(left[i]);
           
        }
       for(int i = 0 ; i < right.size();i++)
       {
           if(right[i] <= root -> val) flag = false;
           merge.push_back(right[i]); 
        }
       merge.push_back(root -> val); 
       return merge; 
    }
    bool isValidBST(TreeNode* root) {
       dfs(root); 
       return flag; 
    }
};
