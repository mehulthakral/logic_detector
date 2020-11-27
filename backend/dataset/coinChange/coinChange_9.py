class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        maxi = 100001
        dp = [maxi]*(amount+1)
        dp[0] = 0
        for c in coins:
            for i in range(c,amount+1):
                dp[i] = min(dp[i],dp[i-c]+1)
                
        if dp[-1]==maxi: return -1
        else: return dp[-1]
