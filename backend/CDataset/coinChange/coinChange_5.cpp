class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
       vector<int> dp(amount+1,amount+1) ;                 //Initialise the vector of size  amount +1 with anything greater than amount
        dp[0]=0;                                           //Base case i.e 0 can be made from 0 coins
        sort(coins.begin(),coins.end());                   // In case if any coin is greater than the amount then we need not check for other coins rather break the loop
        for (int i = 1; i <= amount; i++)                  //Varying all amount ,i represents different amounts i.e subproblems
        {
            for (int j = 0; j < coins.size(); j++)         //Varying all coins,j represents different coins
            {  if(i>=coins[j])
                {
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                    
                }
             else{
                 break;
             }
                  
            }
        }
        return dp[amount]>=amount+1?-1:dp[amount];         //if final cell is greater than amount which is impossible then return -1 else return that cell value
    }
};
