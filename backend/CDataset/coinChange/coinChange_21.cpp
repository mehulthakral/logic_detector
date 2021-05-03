class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[j]=min(dp[j],1+dp[j-coins[i-1]]);
                }
            }
        }
        
        return (dp[amount]>=INT_MAX-1 ? -1 : dp[amount]);
    }
};
