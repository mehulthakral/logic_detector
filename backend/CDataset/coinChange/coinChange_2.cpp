class Solution {
public:    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0)return 0;
        vector<int> dp(amount+1);             //Note that dp[0]=0 because for amount 0 there is no possible way to pay using the given coins
        for(int i=1;i<=amount;i++)
        {
            int t=INT_MAX/2;                     //we cannot use INT_MAX cuz anything above INT_MAX will cause an overflow.
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0)
                    t=min(t,dp[i-coins[j]]+1);
            }
            dp[i]=t;
        }
        return dp[amount]>=INT_MAX/2?-1:dp[amount];      //Sometimes it impossible to get an amount using the coins given eg: amount 3 using coins 2 and 5.
    }
};