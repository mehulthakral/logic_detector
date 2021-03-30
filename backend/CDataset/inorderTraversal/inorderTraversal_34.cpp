class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // traverse the left tree first 
        // display the root information
        // traverse the right sub tree
    vector<int> ans;
        
    if(root ==NULL) return ans; 
    traversal(root,ans);
        
    return ans;
    }
    
    void  traversal(TreeNode* head, vector<int>& ans)
    {
        if(!head) return ;
        traversal(head->left,ans);
        ans.push_back(head->val);
        traversal(head->right,ans);
    }
};




