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
    int maxDepth(TreeNode* root) {
		if(!root)    // Return depth as '0' if the root is NULL.
			return 0;
        queue<TreeNode *> q;    // Queue for BFS
        int ans = 0, s;
        TreeNode * temp;
        q.push(root);
        while(!q.empty()) {
            ans++;    // Increment depth at every level.
            s = q.size();    // 's' is the size of the current level. We will process these many nodes.
            for(int i = 0; i < s; i++) {
                temp = q.front();
                q.pop();
				// Only add non-NULL nodes into the queue.
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};
