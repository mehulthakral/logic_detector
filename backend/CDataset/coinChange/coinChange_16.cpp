class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1); dp[0] = 0;
        for(int i = 1;i<=amount;i++)
        {
            int mi = 100000000;
            for(auto a:coins)
                if(i>=a && dp[i-a]!=-1)  mi = min(mi,dp[i-a]);
            if(mi != 100000000)  dp[i] = 1+mi;
        }
        return dp[amount];
    }
};
