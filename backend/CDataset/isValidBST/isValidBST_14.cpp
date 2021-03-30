class Solution {
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
public:
    bool isValidBST(TreeNode* root) 
    {
        if( root == nullptr )
        {
            return true;
        }
        inorderTraversal(root);
        return isValid();
    }
};
