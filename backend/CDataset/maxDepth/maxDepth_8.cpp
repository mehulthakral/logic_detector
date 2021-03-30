class Solution {
public:
int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int l = maxDepth(root -> left);
    int r = maxDepth(root -> right);
    int ans = max(l, r) + 1;
    return ans;
}
};