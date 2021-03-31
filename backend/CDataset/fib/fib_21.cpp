//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
//Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Fibonacci Number.

class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1 || N == 2) return 1;
        
        int dp[N + 1];
        dp[1] = 1, dp[2] = 1;
        
        for(int i = 3; i <= N; i++){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        
        return dp[N];
    }
};
