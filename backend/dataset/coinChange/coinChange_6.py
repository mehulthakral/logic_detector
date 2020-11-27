class Solution:
    def helper(coins, amount, dp):
        if amount < 0:
            return float('inf')
        if amount == 0:
            return 0
        if amount in dp:
            return dp[amount]
        for i in range(len(coins)):
            use_ci = 1 + helper(coins, amount - coins[i], dp)
            if amount not in dp:
                dp[amount] = use_ci
            else:
                dp[amount] = min(dp[amount], use_ci)       
        return dp[amount]
       
    def coinChange(coins: List[int], amount: int) -> int:
        if amount <= 0:
            return 0
        dp = {}
        result = helper(coins, amount, dp)
        return -1 if result == float('inf') else result
