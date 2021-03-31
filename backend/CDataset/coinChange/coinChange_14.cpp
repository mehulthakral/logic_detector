class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        int dp [n + 1][amount + 1];
        
        for (int i =0; i<coins.size()+1; i++)
        {
            for (int j =0; j<amount+1; j++)
            {
                if (j == 0)
                    dp[i][j] = 0;
                if (i == 0)
                    dp[i][j] = INT_MAX - 1;
            }
        }
        for (int j =1; j<amount+1; j++)
        {
            if (j % coins[0] == 0)
                dp[1][j] = j / coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        }
        for (int i =2; i<coins.size()+1; i++)
        {
            for (int j =1; j<amount+1; j++)
            {
                if (coins[i-1]<=j)
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    if(dp[coins.size()][amount]== INT_MAX - 1)
            return -1;
			
    return dp[coins.size()][amount];    
    }
};
