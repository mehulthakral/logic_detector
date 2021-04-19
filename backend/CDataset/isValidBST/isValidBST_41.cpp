class Solution {
public:
#include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    void GetInorderTree(TreeNode* node, vector<int>& nVector) {
        if(node == nullptr) return;
        if(node->left)  GetInorderTree(node->left, nVector);
        nVector.push_back(node->val);
        if(node->right)  GetInorderTree(node->right, nVector);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        
        vector<int> vecTree;
        GetInorderTree(root, vecTree);
        
        for(int i = 1; i < vecTree.size(); i++) {
            if(vecTree[i-1] >= vecTree[i])
                return false;
        }
        return true;
    }
};
