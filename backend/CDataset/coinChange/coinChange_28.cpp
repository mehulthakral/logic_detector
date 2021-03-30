    int coinChange(vector<int>& coins, int amount) {
        // coin change solution will be stored in dp[i] upto 'amount' where i = amount
		vector<int> dp(amount + 1, -1); // initially all solution upto amount is -1 (unknown)
        dp[0] = 0; // 0 is solution for amount 0
		for (int i = 1; i <= amount; i++) {
            int minCnt = amount + 1;  //minCnt is used to count minimum coin for i amount. initially assigned to coin numbers more than amount
            for (auto v : coins) 
                if( i >= v && dp[i - v] > -1)
                    minCnt = min(dp[i - v], minCnt); /*get the minimum coin count if amount is greater than coin value  and solution exists for that particular coin*/
            if (minCnt != amount + 1)
                dp[i] = minCnt + 1; // update dp[i] if solution exist
        }
        return dp[amount];
    }
