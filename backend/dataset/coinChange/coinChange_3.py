class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins or amount <= 0:
            return 0
        
        coins = set(coins)
        level = [amount]
        visited = set([amount])
        count = 0
        while level:
            count += 1
            temp = []
            for a in level:
                if a in coins:
                    return count
                for c in coins:
                    if a - c > 0 and (a - c) not in visited:
                        temp.append(a - c)
                        visited.add(a - c)
            level = temp
        return -1
