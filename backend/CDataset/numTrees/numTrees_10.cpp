/*
    https://leetcode.com/problems/unique-binary-search-trees/
    
    For a current n, each node 'i' till 'n' can become
    a root, and the elements smaller than 'i' are left 
    subtree nodes and greater than 'i' are part of right subtree.
    Both left and right subtree nodes then again be arranged amongst themselves
*/
class Solution {
public:
    // using bottom-up approach
    int numTreesTabular(int n) {
        if(n <= 1)
            return 1;
        
        vector<int> dp(n + 1, 0);
        // there is exactly one way to get a BST with 0 or 1 node
        dp[0] = dp[1] = 1;
        
        // Cn = Sum( Ci * C((n-1) - i)) , 0 <= i <= n-1
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= i-1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
    
    // using memoization
    int numTreesRec(int n, vector<int>& dp) {
        if(n <= 1)
            return 1;
        
        // for current n, each node 'i' till 'n' can become
        // a root, and the elements smaller than 'i' are left 
        // subtree and greater than 'i' are part of right subtree
        // both left and right subtree nodes then again be arranged amongst themselves
        if(dp[n] == 0) {
            for(int i = 1; i <= n; i++) 
                dp[n] += numTreesRec(i - 1, dp) * numTreesRec(n - i, dp);
        }
        return dp[n];
    }
    
    // driver function for memoization
    int numTreesRecDriver(int n) {
        vector<int> dp(n + 1, 0);
        return numTreesRec(n, dp);
    }
    
    
    int numTrees(int n) {
        // return numTreesRecDriver(n);
        return numTreesTabular(n);
    }
};
