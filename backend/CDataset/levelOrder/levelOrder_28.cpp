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

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root){
           queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            q1.push(root);
            while(!(q1.empty() && q2.empty())){
                vector<int> current;
                while(!q1.empty()){
                    TreeNode* curr = q1.front();
                    if(curr->left) q2.push(curr->left);
                    if(curr->right) q2.push(curr->right);
                    current.push_back(curr->val);
                    q1.pop();
                }
                // printVector(current);
                solution.push_back(current);
                swap(q1,q2);   
            } 
        }
        return solution;
    }
    private:
    vector<vector<int>> solution;
    void swap(queue<TreeNode*>&a,queue<TreeNode*>&b){
        queue<TreeNode*> temp = a;
        a = b;
        b = temp;
    }
};
