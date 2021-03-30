class Solution {
public:
    bool bInit = true;
    bool Validate(TreeNode* node, int& nValue) {        
        if(node == nullptr) return true;
        
        if(!Validate(node->left, nValue))
            return false;
        
        if(bInit) {
            // Key! The only way to set minimum value.
            nValue = node->val;
            bInit = false;
        }
        else if(nValue >= node->val)
            return false;
        nValue = node->val;
        if(!Validate(node->right, nValue))
            return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        
        int nValue = INT_MIN;
        return Validate(root, nValue);
    }
};
