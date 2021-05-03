class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        int left, right;
        return BFSvalid(root, left, right);
    }
    
    bool BFSvalid(TreeNode* root, int& left, int& right){
        int l_left, l_right, r_left, r_right;
        left = root->val;
        right = root->val;
        if(root->left){
            if(!BFSvalid(root->left, l_left, l_right) || l_right >= root->val)  return false;
            left = l_left;
        }
        if(root->right){
            if(!BFSvalid(root->right, r_left, r_right) || r_left <= root->val)  return false;
            right = r_right;
        }
        return true;
    }
};
