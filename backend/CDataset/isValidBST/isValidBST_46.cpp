class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL, *cur = root, *tmp = NULL;
        while( cur ){
            if( cur->left){
                tmp = cur->left;
                while(tmp->right && tmp->right!=cur) tmp = tmp->right;
                if( !tmp->right ){
                    tmp->right = cur;
                    cur = cur->left;
                }
                else{
                    tmp->right = NULL;
                    if( pre && pre->val >= cur->val ) return false;
                    pre = cur;
                    cur = cur->right;
                }
            }
            else{
                if( pre && pre->val >= cur->val ) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};
