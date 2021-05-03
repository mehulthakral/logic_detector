class Solution
{

public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> traversalQueue;
        traversalQueue.push(root);

        while (!traversalQueue.empty())
        {
            int toBeTraversed = traversalQueue.size();

            vector<int> currLevel;
            while (toBeTraversed--)
            {
                TreeNode *currNode = traversalQueue.front();

                currLevel.push_back(currNode->val);
                traversalQueue.pop();

                if (currNode->left)
                    traversalQueue.push(currNode->left);

                if (currNode->right)
                    traversalQueue.push(currNode->right);
            }
            result.push_back(currLevel);
        }
        return result;
    }
};
