class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins: return
        # recursively find all the ways to give change
        memory = {}
        def dp(amount, coins_used=0):
            # have we done this before?
            if amount in memory: return memory[amount]
            # base case
            if amount == 0: return 0
            # try with all coins
            tmp = []
            for coin in coins:
                if amount - coin >= 0: tmp.append(dp(amount-coin, coins_used+1))
                else: tmp.append(float('inf'))
            # save the output in memory before returning
            _min = min(tmp) + 1
            memory[amount] = _min
            return _min
        output = dp(amount)
        return output if output != float('inf') else -1
