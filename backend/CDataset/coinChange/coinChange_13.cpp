class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // unbounded Knspascak Problem
        
        int n = coins.size();
        int m = amount;
        
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 && j==0)
                {
                    t[i][j]=0;
                }
                else if(i==0)
                {
                    t[i][j]=INT_MAX-100;
                }
                else if(j==0)
                {
                    t[i][j]=0;
                }
                else if(coins[i-1]<=j)
                {
                    t[i][j]=min((1+t[i][j-coins[i-1]]),t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
            
        }
        return (t[n][m]==INT_MAX-100)?-1:t[n][m];
    }
};
