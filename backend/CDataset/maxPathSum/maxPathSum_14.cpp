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
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    void __max(TreeNode*, int&);
    int maxPathSum(TreeNode* root) {
        int mx = root -> val;
        __max(root, mx);
        return mx;
    }
};

void Solution::__max(TreeNode* root, int& mx) {
    if(!root) return;
    
    __max(root -> left, mx);
    __max(root -> right, mx);
    
    if(root -> left && root -> right) {
        auto left = root -> left -> val;
        auto right = root -> right -> val;
        
        mx = std::max(mx, root -> val + left + right);        

        root -> val = std::max(root -> val, std::max(left, right) + root -> val); 
    }
    
    else if(root -> left)
        root -> val = std::max(root -> val, root -> val + root -> left -> val);
    
    else if(root -> right)
        root -> val = std::max(root -> val, root -> val + root -> right -> val);
    
    if(root -> val > mx) mx = root -> val;        
}
