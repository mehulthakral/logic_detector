class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
		
        while(curr) {
            if(curr->left) {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)
                    prev = prev->right;
                if(prev->right == curr) {
                    result.push_back(curr->val);
                    prev->right = NULL;
                    curr = curr->right;
                } else {
                    prev->right = curr;
                    curr = curr->left;
                }
            } else {
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return result;
    }
    
};
