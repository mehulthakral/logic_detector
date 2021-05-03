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
#include<vector>
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        vector<int> array;
        initialize(root);
        while(hasNext())
        {
            array.push_back(next());
        }
        int n = array.size();
        int i;
        if(n==0)
            return true;
        int tempvalue = array[0];
        for(i=1; i<n; i++)
        {
            if(array[i] <= tempvalue)
                return false;
            tempvalue = array[i];
        }
        return true;
    }
    private:
    TreeNode *node;
    vector<TreeNode*> leftMostNodes;
    
    void initialize(TreeNode* root)
    {
        node = root;
    }
    
    bool hasNext()
    {
        while(node)
        {
            leftMostNodes.push_back(node);
            node = node->left;
        }
        if(leftMostNodes.size() == 0)
            return false;
        else
            return true;
    }
    
    int next()
    {
        int value;
        node = leftMostNodes.back();
        leftMostNodes.pop_back();
        value = node->val;
        node = node->right;
        return value;
    }
};