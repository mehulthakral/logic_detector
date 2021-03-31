class Solution {
public:
bool isValidBSTHelper(TreeNode* root, long min, long max){
    if(root == NULL){
        return true;
    }
    if(root -> val > min && root -> val < max){
        bool temp1 = isValidBSTHelper(root->left, min, root->val);
        bool temp2 = isValidBSTHelper(root->right, root->val, max);
        return temp1 && temp2;
    }
    return false;
}
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}
};