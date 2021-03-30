class Solution {
public:
    int impossible=0;
    int minimum(int amount,vector<int>& coins,vector<int>& memo){
        
        if(amount==0){
            ++impossible;
            return 0;
        }
        else if(amount<0)
            return 10000;
        
        else if(memo[amount]!=0)
            return memo[amount];
        
        else{
            int min_ways=INT_MAX;
        for(int i=0;i<coins.size();i++){
          //  cout<<amount-coins[i]<<endl;
            int ways=1+minimum(amount-coins[i],coins,memo);
            if(ways<min_ways)
                min_ways=ways;
        }
            memo[amount]=min_ways;
            return min_ways;
        }
        
        return 0;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount==0)
            return 0;
       
        
        vector<int> memo((amount+1),0); 
        int ways=minimum(amount,coins,memo);
        
        if(impossible==0)
            return -1;
        
        return ways;
        
    }
};
