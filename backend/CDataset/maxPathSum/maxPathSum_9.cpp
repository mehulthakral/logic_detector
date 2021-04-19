class Solution {    
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxPathSum( TreeNode* root ) {
        int maxSum = INT_MIN;
        helper( root, maxSum );
        return maxSum;
    }
    int helper( TreeNode* node, int &maxSum ) {
        if( !node ) return 0;
        int left = 0, right = 0;
        if( node->left )  left = helper( node->left, maxSum );
        if( node->right ) right = helper( node->right, maxSum );
        
        // node+left or node+right or node
        int leftOrRightOrNode = max( node->val, node->val + max( left, right ) );
        // set maxSum to max of maxSum, node+left+right, node+left, node+right, node
        maxSum = max( maxSum, max( node->val + left + right, leftOrRightOrNode ) );        
        return leftOrRightOrNode;
    }
};
