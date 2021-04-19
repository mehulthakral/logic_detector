class Solution {
public:
#include<vector>
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) 
    {
        if( root == nullptr )
        {
            return true;
        }
        inorderTraversal(root);
        return isValid();
    }
private:
    vector<int> values;
    void inorderTraversal(TreeNode* root)
    {
        if( root )
        {
            inorderTraversal(root->left);
            values.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
    bool isValid()
    {
		return is_sorted(values.begin(), values.end(), [](const int& a, const int& b) {return a <= b; });
    }
};
