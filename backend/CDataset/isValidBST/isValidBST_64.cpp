class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    bool isValidBST(TreeNode* root) {
        TreeNode *curNode = root, *preNode;
        long long last_val = LLONG_MIN;
        while(curNode)
        {
            if(!curNode->left)
            {
                if(curNode->val <= last_val)
                    return false;
                last_val = curNode->val;
                curNode = curNode->right;
            }
            else
            {
                preNode = curNode->left;
                while(preNode->right && preNode->right != curNode)
                    preNode = preNode->right;
                if(!preNode->right)
                {
                    preNode->right = curNode;
                    curNode = curNode->left;
                }
                else
                {
                    if(curNode->val <= last_val)
                        return false;
                    last_val = curNode->val;
                    preNode->right = nullptr;
                    curNode = curNode->right;
                }
            }
        }
        return true;   
    }
};