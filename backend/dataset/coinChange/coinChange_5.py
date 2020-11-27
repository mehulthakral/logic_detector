from functools import lru_cache


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins:
            return
        # recursively find all the ways to give change
        @lru_cache(maxsize=None)
        def dp(amount):
            # base case
            if amount == 0:
                return 0
            # try with all coins
            tmp = []
            for coin in coins:
                if amount - coin >= 0:
                    tmp.append(dp(amount - coin))
            # backtrack to the top of the DAG increase min coins used + 1
            return min(tmp, default=float("inf")) + 1

        output = dp(amount)
        return output if output != float("inf") else -1
