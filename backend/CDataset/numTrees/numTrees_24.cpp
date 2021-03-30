int func(int n,vector<int>&dp){
        if(n==1 || n==0)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        int temp=0;
        for(int i=1;i<=n;i++){
            temp+=func(i-1,dp)*func(n-i,dp);
        }
        return dp[n]=temp;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
    }
