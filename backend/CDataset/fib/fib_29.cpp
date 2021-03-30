int fib(int N) {
        vector<int> dp(N+2, 0);
        dp[1] = 1;
        for(int i = 2; i <= N; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }    
        return dp[N];
    }
	
