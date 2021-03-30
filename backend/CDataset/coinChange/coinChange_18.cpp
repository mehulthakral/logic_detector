int coinChange(vector<int>& coins, int amount) { 
        int dp[amount+1];
        dp[0] = 0;    
        for(int e=1;e<amount+1;e++)
            dp[e] = amount+1;
        for(int i=1;i<amount+1;i++){
            for(int j:coins){
                if(i-j>=0)
                    dp[i] = min(dp[i],dp[i-j]+1);
            }
        }
        if(dp[amount]==amount+1)
            return -1;
        
        return dp[amount];
    }
