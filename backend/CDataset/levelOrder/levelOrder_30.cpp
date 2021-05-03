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
        if(root==NULL)
            return ans;
        
        leveltraversal(root,0); // Function call
        
        return ans;   
    }
private:
    vector<vector<int>> ans;  // Answer vector, to be retuned
    void leveltraversal(TreeNode* root, int level)
    {
        vector<int> temp(1,0);  //To push first vaue in a certain level in ans as it will only take a vector
        
        if(ans.empty() || ans.size()<=level)
        {
            temp[0]=root->val;
            ans.push_back(temp);
            temp.clear();
        }
        else
        {
            ans[level].push_back(root->val);
        }
        
        if(root->left!=NULL)    // Traversing Left Child
           leveltraversal(root->left,level+1);
        
        if(root->right!=NULL)   // Traversing Right Child
            leveltraversal(root->right,level+1);
    } 
};
