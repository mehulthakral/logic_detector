int isValid(TreeNode* node, int min, int max)  
{  
    
    if (node==NULL)  
        return 1;  
             
    if (node->data < min || node->data > max)  
        return 0;  
      
    return
        isValid(node->left, min, node->data-1) && // Allow only distinct values  
        isValid(node->right, node->data+1, max); // Allow only distinct values  
}  
 bool isValidBST(TreeNode* root) {        
         
        return isValid(root,INT_MIN,INT_MAX);     
    }
};
  
