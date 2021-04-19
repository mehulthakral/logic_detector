class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        queue<int> inorder;
        
        dfs(root, inorder);
        
        int former = inorder.front(); inorder.pop();
        while(!inorder.empty()){
            if(former >= inorder.front()) return false;
            
            former = inorder.front();
            inorder.pop();
        }
        
        return true;
    }
    
    void dfs(TreeNode* root, queue<int>& que){
        if(root == NULL) return;
        
        dfs(root->left, que);
        que.push(root->val);   
        dfs(root->right, que);
    }
};
