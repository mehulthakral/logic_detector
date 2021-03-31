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
    void inorder(TreeNode* root,stack<pair<TreeNode*,int>> &s,vector<int> &ans){
        while(!s.empty()){
            while(s.top().first->left && s.top().second==0){
                s.top().second=1;
                s.push(make_pair(s.top().first->left,0));
            }
            ans.push_back(s.top().first->val);
            s.top().second=1;
            pair<TreeNode*,int> temp=s.top();
            s.pop();
            if(temp.first->right){
                s.push(make_pair(temp.first->right,0));
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*,int>> s;
        /*will have to maintain if left subtree has
        been checked for this node or not 0 for not checked 1 for checked*/
        if(root){
            s.push(make_pair(root,0));
            inorder(root,s,ans);
        }
        return ans;
    }
};
