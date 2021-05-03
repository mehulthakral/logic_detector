class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool inorder(TreeNode* node,long& min)
    {
        bool l_find,r_find;
        if(node==NULL)
            return true;
        l_find=inorder(node->left,min);
        if(l_find==false)
            return false;
        if(node->val<=min)
            return false;
        min=node->val;
        r_find=inorder(node->right,min);
        if(r_find==false)
            return false;
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        long x=LONG_MIN;
        return inorder(root,x);
    }
};
