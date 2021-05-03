class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
int isValid(TreeNode* node, int min, int max)  
{  
    
    if (node==NULL)  
        return 1;  
             
    if (node->val < min || node->val > max)  
        return 0;  
      
    return
        isValid(node->left, min, node->val-1) && // Allow only distinct values  
        isValid(node->right, node->val+1, max); // Allow only distinct values  
}  
 bool isValidBST(TreeNode* root) {        
         
        return isValid(root,INT_MIN,INT_MAX);     
    }
};