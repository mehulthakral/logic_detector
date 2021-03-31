class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};
