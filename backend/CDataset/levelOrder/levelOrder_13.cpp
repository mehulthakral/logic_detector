/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
		vector<vector<int>> ans;

		if (!root) {
            return ans;
        }
        
        queue<TreeNode*> q;
        
        q.push(root);

        while (!q.empty()) {
            vector<int> t;
            int s = q.size();
            
            while (s--) {
                TreeNode* r = q.front();
                q.pop();
                
                t.push_back(r->val);
                
                if (r->left != nullptr) 
                    q.push(r->left);
                
                if (r->right != nullptr)
                    q.push(r->right);
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};
