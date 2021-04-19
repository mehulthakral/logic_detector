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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        TreeNode* cur = root;
        
        int curDepth = 0, maxDepth = 0;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(make_pair(cur, ++curDepth));
                curDepth = s.top().second;
                
                cur = cur->left;
            }
            else {
                cur = s.top().first->right;
                curDepth = s.top().second;
                
                s.pop();
            }
            
            maxDepth = max(maxDepth, curDepth);
        }
        
        return maxDepth;
    }

private:
    stack<pair<TreeNode*, int>> s;
};
