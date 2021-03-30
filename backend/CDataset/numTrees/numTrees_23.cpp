int func(int l,int r,vector<vector<int>>&dp){
        if(r<l){return 1;}
        if(dp[l][r]!=-1)return dp[l][r];
        int temp=0;
        for(int i=l;i<=r;i++){
            temp+=func(l,i-1,dp)*func(i+1,r,dp);
        }
        return dp[l][r]=temp;
    }
    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(1,n,dp);
    }