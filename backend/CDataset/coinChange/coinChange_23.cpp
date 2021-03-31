class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        
        // for every amt = [1, amount], find min coins req
        for(int amt=1; amt<=amount ; amt++){
            dp[amt] = INT_MAX;
            for(int i=0 ; i<coins.size() ; i++){
                if(amt - coins[i] >= 0 && 
                   dp[amt-coins[i]] != INT_MAX)
                        dp[amt] = min(dp[amt], dp[amt-coins[i]]+1);
            }
        }
        
        if(dp[amount] <= amount)
            return dp[amount];
        
        return -1;
    }
};
