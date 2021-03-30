class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        for(int i=0;i<=amount;i++) dp[i]=INT_MAX-1;// -1 for not to overflow
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(auto x: coins)
            {
               
                    if(i-x>=0)
                {
                    dp[i]=min(dp[i],dp[i-x]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX-1) return -1;
        return dp[amount];
    }
};
