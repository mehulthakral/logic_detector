const int m = 1e4 + 100; // max allowed amount < 1e4
class Solution {
    int dp[m];
public:
    int coinChange(vector<int>& coins, int amount){
        sort(coins.begin(), coins.end()); // sort on basis on coin value
        
        for(int i=0;i<=amount;i++)
            dp[i] = INT_MAX; // initialize
        
        dp[0] = 0; // no coin needed for 0 value
        
        for(int i=coins[0];i<=amount;i++){ // we can only make values > coins[0]
            for(int j=0;j<coins.size();j++){
                if(i < coins[j]) // we cant take any coin which comes after this
                    break;
                if(dp[i-coins[j]]!=INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);// recurrence obvious
            }
        }
        
        if(dp[amount]==INT_MAX)
            return -1;
        
        return dp[amount];
    }
};
