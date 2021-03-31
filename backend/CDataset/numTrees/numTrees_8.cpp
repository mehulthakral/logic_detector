class Solution {
public:
    int numTrees(int n) {
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        for(int l=2;l<=n;l++) {
            int i = 0;
            for(int j=l-1;j<n;j++) {
                for(int k=0;k<=j;k++) {
                    dp[i][j] += ((k-1 >= i ? dp[i][k-1] : 1) * (k+1 < j ? dp[k+1][j] : 1));
                }
                i++;
            }
        }
        return dp[0][n-1];
    }
};