class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };void isValidHelper(TreeNode* root, bool& is_valid, long& low){
        
        if(root == NULL){
            return;
        }
        
        isValidHelper(root->left,is_valid,low);
        
        if(low < root->val){
            low = root->val;
        }
        else{
            is_valid = false;
            return;
        }
        
        isValidHelper(root->right,is_valid,low);
        
    }

    bool isValidBST(TreeNode* root) {
        
        bool is_valid = true;
        long low = LONG_MIN;
        
        isValidHelper(root,is_valid,low);
        
        return is_valid;
        
    }
};