class Solution:
    dp = {}
    def numTrees(self, n: int) -> int:
        nodes = {}
        if n == 1 or n == 0:
            return 1
        elif n == 2:
            return 2
        elif n in self.dp:
            return self.dp[n]
        for i in range(1, n+1):
            nodes[i] = self.numTrees(i-1) * self.numTrees(n-i)

        self.dp[n] = sum(nodes[i] for i in nodes)
        return self.dp[n]
