class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<double> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        // dp[i] represents the fewest number of coins to make up the amount i
        for (int i = 1; i <= amount; i++) {
            
            for (auto coin : coins) {
                
                if (coin <= i) {
                    
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
