class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        min_den  = [(amount+1) for i in range(0,amount+1)]
        min_den[0] = 0
        for i in range(1,len(min_den)):
            min_val = min_den[i]
            
            for j in coins:
                if i-j >=0:
                    min_val = min(min_val, min_den[i-j]+1)
                                        
            min_den[i] = min_val

        if min_den[-1]>amount:
            return -1
        else:
            
            return min_den[-1]
