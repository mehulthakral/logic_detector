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
private:
    TreeNode* node;
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
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        initialize(root);
        while(hasNext())
        {
            result.push_back(next());
        }
        return result;
    }
};