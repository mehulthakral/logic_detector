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
    
    // Recursive Method
    
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    vector<int> inorderTraversal(TreeNode* root)
    {
        TreeNode *ptr = root;
        vector <int> ans;
        stack <TreeNode*> address;
        
        if(root == NULL)
            return ans;
        
        // until address stack is empty and ptr points to NULL i.e. Traversal is over
        while( !address.empty() || ptr != NULL )
        {
            // if ptr points to a child
            if(ptr != NULL)
            {
                // pushing the address to the stack
                address.push(ptr);
                // moving left
                ptr = ptr->left;                    // LEFT
            }
            else
            {
                // popping the address and making ptr point to it, kinda backtrack a step
                ptr = address.top();
                address.pop();
                // printing or pushing the value of node to array
                ans.push_back(ptr->val);            // PRINT
                // movinf left
                ptr= ptr->right;                    // RIGHT
            }
        }  
        return ans;
    }
};
