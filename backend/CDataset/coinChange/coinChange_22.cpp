#define MAX 9999
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
			
        int dp[coins.size()+1][amount+1];
		
        for(int i=0;i<=coins.size();i++)
            for(int j=0;j<=amount;j++)
                if(i==0||j==0)
                 dp[i][j]=MAX;
				 
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else if(coins[i-1]==j)
                    dp[i][j]=1;
                else
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }
		
        if(dp[coins.size()][amount]==MAX)
            return -1;
			
        return dp[coins.size()][amount];
    }
};
