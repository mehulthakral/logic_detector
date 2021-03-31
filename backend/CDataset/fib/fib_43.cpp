class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        for(int i=0;i<=n;i++){
            if(i==0 || i==1)
                dp[i]=i;
            else{
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
   
};