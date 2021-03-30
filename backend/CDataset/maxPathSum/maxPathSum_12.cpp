class Solution {
private:  
    // Partial sum is like a logger, it logs the max we've seen so far.
    int maxHelper(TreeNode* root, int& partialSum) {
        if (!root) return 0;
        int leftMine = maxHelper(root->left, partialSum), rightMine = maxHelper(root->right, partialSum); 
        partialSum = max(partialSum, leftMine + rightMine + root->val); // Log the max we've seen
        return max(0, root->val + max(leftMine, rightMine)); // Here we are returning paths
    } // Since we are looking for the longest single path, we make a decision between
	// returning our current value plus either the left or the right path.
	// If a path sums to negative, we don't want to return it, it won't add to our longest path
      // If a path is positive, it will have a positive impact on our max path, so we want to 
	  // return it as opposed to returning 0.
public:
    int maxPathSum(TreeNode* root) {
        int res{numeric_limits<int>::min()};
        maxHelper(root, res);
        return res;
    }
};