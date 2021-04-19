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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        std::function<void(TreeNode*)> inorder = [&](TreeNode* root) {
            if(root == nullptr) return;
            
            inorder(root -> left);
            ans.push_back(root -> val);
            inorder(root -> right);
        };
        
        inorder(root);
        
        return ans;
    }
};
