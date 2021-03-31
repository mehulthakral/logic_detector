//I have past 72/74 testcase, the wrong testcase [3,1,5,0,2,4,6,null,null,null,3],
//which expected false, 
//he said my codes returning true, but I even test it in my IDE,
// no problem...so for help!
class Solution {
public:
bool isValidBST(TreeNode* root) {
      return iVB(root,0,0);
}
bool iVB(TreeNode * root, int flag, int fatherVal)//flag 1 left 2 right
{
    if (root == NULL)
        return true;
    if (root->left != NULL)
    {
        if (root->left->val >= root->val)
            return false;
        if (flag==2 && root->left->val <= fatherVal)//right subtree's left son 
                                //must greater than the father node's val
            return false;
    }
    if (root->right != NULL)
    {
        if (root->right->val <= root->val)
            return false;
        if (flag==1 && root->right->val >= fatherVal)//left subtree's right son 
                              //must greater than the father node's val
            return false;
    }
    return iVB(root->left,1,root->val) && iVB(root->right,2,root->val);
}
};