int fib(int n) {
        vector<int> dp(n+1,-1);
        return findFib(n,dp);
    }
    int findFib(int n,vector<int>& dp){
        if(n == 0 || n==1)
            return n;
        if(dp[n]!= -1)
            return dp[n];
        dp[n]=findFib(n-1,dp) + findFib(n-2,dp);
        return dp[n];
    }