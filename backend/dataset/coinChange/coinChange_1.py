from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins or amount <= 0:
            return 0
        
        f = [float('inf')] * (amount + 1)
        f[0] = 0
        for i in range(1, amount + 1):
            for c in coins:
                if i >= c:
                    f[i] = min(f[i], f[i - c] + 1)
        return f[amount] if f[amount] != float('inf') else -1
