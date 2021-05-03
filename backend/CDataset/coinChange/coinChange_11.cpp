class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(auto x:coins)
            for(int i=x; i<=amount; i++)
                dp[i] = min(dp[i],dp[i-x]+1);
        int ans = -1;
        if(dp[amount]!=amount+1) ans = dp[amount];
        return ans;
    }
};
