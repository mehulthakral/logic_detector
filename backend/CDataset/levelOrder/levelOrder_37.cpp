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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return ans;
        
        q.push(root);
        
        vector<int> curVec;
        while (!q.empty()) {
            int sz = q.size();
            
            for (auto i = 0; i < sz; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                
                curVec.push_back(cur->val);
                
                if (cur->left) {
                    q.push(cur->left);
                }
                
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            
            ans.push_back(curVec);
            curVec.clear();
        }
        
        return ans;
    }
    
private:
    queue<TreeNode*> q;
    vector<vector<int>> ans;
};
