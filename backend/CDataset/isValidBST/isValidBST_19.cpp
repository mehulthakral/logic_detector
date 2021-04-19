class Solution {

public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        
        return flag;
        
    }
    
    bool flag = true;
    stack<int> s;
    
    void inorder(TreeNode* node){
        if(node){
            inorder(node->left);
            
            if(!s.empty() and s.top() >= node->val){
                flag = false;
                return;
            }
            s.push(node->val);
            
            
            inorder(node->right);
        }
        else{
            return;
        }
    }
    
};
