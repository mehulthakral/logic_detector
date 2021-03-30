//memoization 
class Solution {
public:
    int fib(int n,int dp[]) {
        if (n <= 1) 
           return n; 
        
        if (dp[n] != -1) 
           return dp[n];
        
        return dp[n]=fib(n-1) + fib(n-2);
    }
    int fib(int n) {
        int dp[31];
        memset(dp, -1, sizeof(dp)); 
        return fib(n,dp);
    }
};