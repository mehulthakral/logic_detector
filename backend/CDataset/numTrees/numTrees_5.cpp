class Solution {
public:
    int numTrees(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        vector<int> dp(n+1, 1);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=0;
            for(int j=0;j<i;j++)
            {
                dp[i]+=(dp[j]*dp[i-j-1]);
            }
        }
        return dp[n];
    }
};
