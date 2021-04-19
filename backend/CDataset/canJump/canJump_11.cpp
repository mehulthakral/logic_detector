class Solution {
public:

bool canJump(vector<int>& nums) {
    
    int n = nums.size();
    
    if(!n || (n>1 && !nums[0]))
        return false;
    
    if(nums[0] >= (n-1))
        return true;
    
    vector<bool> dp(n,false);
    dp[n-1] = true;
    
    for(long i=n-2;i>=0;i--)
    {
        for(long j=i+nums[i];j>i;j--)
        {
            if(j >= n || (dp[j] == true))
            {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[0];
}
};