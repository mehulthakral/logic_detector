class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins or amount <= 0:
            return 0
        
        f = [float('inf')] * (amount + 1)
        f[0] = 0
        for c in coins:
            for a in range(c, amount + 1):
                f[a] = min(f[a], f[a - c] + 1)
        return f[amount] if f[amount] != float('inf') else -1
