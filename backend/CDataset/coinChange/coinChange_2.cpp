class Solution {
    int dp[12][10001]={};
public:
    int solve(vector<int>& coins,int index,int amount){
        //Base Cases
        if(amount==0)
            return 0;
        if(amount<0 || index<0)
            return -1;
        
        //If calculated previously ,return directly
        if(dp[index][amount])
            return dp[index][amount];
        
        //Calculate result for amount and store in dp matrix before returning result
        int coins1=solve(coins,index-1,amount);
        int coins2=solve(coins,index,amount-coins[index]);
        if(coins1==-1 && coins2==-1)
            return dp[index][amount]=-1;
        if(coins1!=-1 && coins2!=-1)
            return dp[index][amount]=min(coins1,coins2+1);
        return dp[index][amount]=(coins1==-1 ? coins2+1 : coins1);
    }
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins,coins.size()-1,amount);
    }
};
