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
struct DepthNode : public TreeNode
{
    static constexpr TreeNode* SENTINEL = reinterpret_cast<TreeNode*>(0xDEAD71EE);
    
    int depth;
    DepthNode(int d)
        : TreeNode(-1)
        , depth(d)
    {
        // cheating a bit
        left = right = SENTINEL;
    }
};
 
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
        {
            return vector<vector<int>>();
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(new DepthNode(0));
        
        vector<vector<int>> result;
        vector<int> current_depth;
        
        while (!q.empty())
        {
            TreeNode *node = q.front(); q.pop();
            assert (node != NULL);
            if (node->left == DepthNode::SENTINEL && node->right == DepthNode::SENTINEL)
            {
                result.push_back(current_depth);
                current_depth.clear();
                
                if (!q.empty())
                {
                    DepthNode *dnode = static_cast<DepthNode*>(node);
                    DepthNode *new_depth_node = new DepthNode(dnode->depth + 1);
                    q.push(new_depth_node);
                }
            }
            else
            {
                current_depth.push_back(node->val);
                
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        
        return result;
    }
};