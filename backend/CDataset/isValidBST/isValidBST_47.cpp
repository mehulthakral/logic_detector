    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(isValidBST(root->left) && isValidBST(root->right)){
            TreeNode* leftLargest = root->left;
            while(leftLargest != NULL && leftLargest->right !=NULL){
                leftLargest = leftLargest->right;
            }
            if(leftLargest != NULL && leftLargest->val >= root->val){
                return false;
            }
            TreeNode* rightSmallest = root->right;
            while(rightSmallest != NULL && rightSmallest->left != NULL){
                rightSmallest = rightSmallest->left;
            }
            if(rightSmallest != NULL && rightSmallest->val <= root->val){
                return  false;
            }
            return true;
        }
        return false;
    }