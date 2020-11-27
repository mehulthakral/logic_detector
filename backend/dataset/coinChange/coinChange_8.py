class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        memo = [float("inf")]*(amount+1)
        memo[0] = 0
        
        for i in range(1,amount+1):
            for coin in coins:
                
                if i-coin >= 0 and memo[i] > memo[i-coin]+1:
                    memo[i] = memo[i-coin]+1

        if memo[amount] == float("inf"):
            return -1
        return memo[amount]
		           
