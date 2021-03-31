/*
dp[amount] = dp[amount-coins[i]] + 1;
*/

class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        long long int n=nums.size();
        sort(nums.begin(),nums.end());
        //dp[i] -> min no of coins required to make amount 'i'
        vector<long long int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(long long int i=0;i<n;i++){
            if(nums[i]>amount)
                break;
            dp[nums[i]]=1;
        }
        
        for(long long int i=1;i<=amount;i++){
            if(dp[i]!=INT_MAX){
                for(long long int j=0;j<n && i+nums[j]<=amount;j++){
                    int new_val=i+nums[j];
                    if(new_val>amount)
                        break;
                    dp[new_val]=min(dp[new_val],dp[i]+1);
                }
            }
            
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
