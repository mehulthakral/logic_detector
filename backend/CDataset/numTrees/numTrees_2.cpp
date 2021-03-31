class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            int total=0;
            for(int j=0;j<i/2;j++)
                total+=dp[j]*dp[i-j-1]*2;
            dp[i]=total+(i%2==0?0:dp[i/2]*dp[i/2]);
        }
        return dp[n];
    }
};
