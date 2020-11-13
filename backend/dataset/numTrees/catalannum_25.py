class Solution:
    def numTrees(self, n: int) -> int:
        if n <= 2:
            return n
        
        dp = {0: 1, 1: 1, 2: 2}
        for i in range(3, n+1): #n+1 so that N is also included
            #now assume every node as a root and then calculate
            #start from 1, because, I assume I take 1st node as the root
            sm = 0
            for j in range(1, i+1):
                sm += dp[j-1]*dp[i - j]
            dp[i] = sm
        return dp[n]