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
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root)
        return {};
    
    vector<vector<int>> ans;
    queue<TreeNode*> q1,q2;
    int level=0;
    TreeNode *temp;
    
    q1.push(root);
    
    while(!(q1.empty() && q2.empty())){
        if(q1.empty()){
            ans.push_back({});
            while(!q2.empty()){
                temp=q2.front();
                q2.pop();
                ans[level].push_back(temp->val);
                
                if(temp->left)
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
            }
        }
        else{
            ans.push_back({});
            while(!q1.empty()){
                temp=q1.front();
                q1.pop();
                ans[level].push_back(temp->val);
                
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
            }
        }
        level++;
    }
    
    return ans;
}
};
