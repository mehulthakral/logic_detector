class Solution {
private:
    int min = INT_MIN;
    bool first = true;
public:
    bool isValidBST(TreeNode* root) {
        if( !root )
            return true;
        bool tag = true;
        tag = tag && isValidBST( root->left );
        if( ( first && root->val == INT_MIN ) || min < root->val )
        {
            min = root->val;
            first = false;
        }
        else
            tag = false;
        tag = tag && isValidBST( root->right );
        return tag;
    }
};