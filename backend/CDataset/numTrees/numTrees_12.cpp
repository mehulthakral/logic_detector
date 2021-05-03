class Solution {
public:
    int numTrees(int n) {
        // trival cases
        if (n <= 1) {
            return n;
        }
        // dp: dp[k] = sum_{j=0}^{k-1} (dp[j] * dp[k-j-1]) 
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int k(2); k <= n; ++k) {
            dp[k] = 0;
            for (int j(0); j < k; ++j) {
                dp[k] += dp[j] * dp[k-j-1];
            }
        }
        return dp[n];
    }
};
