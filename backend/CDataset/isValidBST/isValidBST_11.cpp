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
    void inorder(vector<int> &v, TreeNode* root){
        if(root!=NULL){
            inorder(v,root->left);
            v.push_back(root->val);
            inorder(v,root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> v;
        inorder(v,root);
        for(int i=0;i<v.size()-1;i++)
            if(v[i]>=v[i+1])
                return false;
        return true;
    }
};
