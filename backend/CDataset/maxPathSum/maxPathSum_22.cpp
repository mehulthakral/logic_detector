/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        if (!root)
            return 0;

        // The idea is simple:
        // For each subtree rooted at node "root", the maximal path sum can be
        // calculated by:
        //
        // MAX | root->val
        //     | root->val + PathSum(root->left)
        //     | root->val + PathSum(root->right)
        //     | root->val + PathSum(root->left) + PathSum(root->right)
        //
        // To pass an optimal path to the ancestors, we just select:
        //
        // MAX | root->val
        //     | root->val + PathSum(root->left)
        //     | root->val + PathSum(root->right)

        int max = root->val;
        DivideAndConquer(root, &max);
        return max;
    }

private:
    int DivideAndConquer(TreeNode* root, int* p_max)
    {
        int curr, ret_curr, local_max;
        local_max = curr = ret_curr = root->val;

        int ret_left;
        if (root->left) {
            ret_left = DivideAndConquer(root->left, p_max);
            if (ret_left > local_max)
                local_max = ret_left;

            int sum_left = ret_left + curr;
            if (sum_left > local_max)
                local_max = sum_left;

            if (sum_left > ret_curr)
                ret_curr = sum_left;
        }

        int ret_right;
        if (root->right) {
            ret_right = DivideAndConquer(root->right, p_max);
            if (ret_right > local_max)
                local_max = ret_right;

            int sum_right = ret_right + curr;
            if (sum_right > local_max)
                local_max = sum_right;

            if (sum_right > ret_curr)
                ret_curr = sum_right;
        }

        if (root->left && root->right) {
            int sum_both = curr + ret_left + ret_right;
            if (sum_both > local_max)
                local_max = sum_both;
        }

        if (local_max > *p_max)
            *p_max = local_max;
        return ret_curr;
    }
};