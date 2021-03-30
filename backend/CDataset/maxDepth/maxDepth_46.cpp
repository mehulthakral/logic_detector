class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0, preLevelNodes = 0;
        queue<TreeNode *> q;
        TreeNode *temp = NULL;
        
        if (root == NULL) return depth;
        
        q.push(root);
        ++depth, ++preLevelNodes;
        
        while (!q.empty())
        {
            preLevelNodes = q.size();
            while (preLevelNodes--)
            {
                temp = q.front();
            
                if (temp->left != NULL) 
                    q.push(temp->left);
                if (temp->right != NULL) 
                    q.push(temp->right);
                q.pop();
            }
            if (!q.empty())
                ++depth;
        }
        
        return depth;
    }
};