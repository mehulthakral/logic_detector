class Solution:
    def coinChange(self, coins:List[int], amount:int)->bool:
        his, coins, queue, step = set(), set(coins), {0}, 1
        
        if amount == 0: return 0
        if amount in coins: return 1
        
        while queue:
            new_queue = set()
            for now in queue:
                for i in coins:
                    this = now+i
                    if this in his or this>amount: 
                        continue
                    else:
                        his.add(this)

                    if amount-this in coins:
                        return step+1
                    else:
                        new_queue.add(this)
                        
            queue = new_queue
            step += 1
        return -1
