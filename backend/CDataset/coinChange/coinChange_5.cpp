class Solution {
public:
    int solve(vector<int>&coins,int idx,int amt,vector<vector<int>>&dp)
    {
        if(amt<0 || idx>=coins.size()) return 100005;
        if(amt==0) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        return dp[idx][amt] = min(1+solve(coins,idx,amt-coins[idx],dp),solve(coins,idx+1,amt,dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+5,vector<int>(amount+5,-1));
        int ans = solve(coins,0,amount,dp); 
        return (ans == 100005)?-1:ans;
    }
};
