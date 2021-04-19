class Solution {

public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    //AC - Morris Traversal;
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        while(root)
        {
            if(!root->left)
            {
                v.push_back(root->val);
                root = root->right;

            }
            else
            {
                TreeNode *pre = root->left;
                while(pre->right && pre->right!=root) pre = pre->right;
                if(!pre->right)
                {
                    pre->right = root;
                    root = root->left;
                }
                else
                {
                    v.push_back(root->val);
                    root = root->right;
                    pre->right = NULL;
                }
            }
        }
        return v;
    }
    private:
    void traverse(TreeNode* root, vector<int>& v)
    {
        if(!root) return;
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }
};