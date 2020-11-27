class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort()
        changes=[amount+1]*(amount+1)
        changes[0]=0
        for i in range(1,amount+1):
            for coin in coins:
                if coin>i:
                    break
                else:
                    changes[i]=min(changes[i],changes[i-coin]+1)
        return changes[-1] if changes[-1]!=(amount+1) else -1
