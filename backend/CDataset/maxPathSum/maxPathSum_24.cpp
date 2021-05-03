class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        maxPathSumHelper(root, &max);
        return max;
    }
private:
    int maxPathSumHelper(TreeNode* root, int* max)
    {   
        // DFS: depth first search
        if(root == NULL)
            return 0;
        int left = maxPathSumHelper(root->left, max);
        int right = maxPathSumHelper(root->right, max);
        int three = root->val;
        if(left > 0)
            three = three + left;
        if(right > 0)
            three = three + right;
        if(three > *max)
            *max = three;
            
        int two = root->val;
        if(left > right && left > 0)
            two = two + left;
        else if(right > left && right > 0)
            two = two + right;
        return two;
    }
};