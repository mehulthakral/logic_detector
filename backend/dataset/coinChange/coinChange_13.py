class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        ## RC ##
        ## APPROACH : DP ##
        
		## TIME COMPLEXITY : O(N^2) ##
		## SPACE COMPLEXITY : O(N) ##

        dp = [0] + [amount + 1] * amount                                # fill invalid amount i.e amount + 1 for all amounts ranging from 0 to amount.
        for value in range(amount+1):                                   # for each value till amount
            for coin in (coins):                                        # for each coin
                if(coin <= value):                                      # check if this coin can be used make value i.
                    dp[value] = min(dp[value], 1 + dp[value - coin])    # 1 => current coin included, check the min coins required to make remaining value i.e  value - coin                    
        return -1 if(dp[amount] > amount) else dp[amount]
