class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        TreeNode *temp = root;
        
        while (!s.empty() || temp != NULL)
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            
            temp = s.top();
            ret.push_back(temp->val);
            s.pop();
            temp = temp->right;
        }
        
        return ret;
    }
};