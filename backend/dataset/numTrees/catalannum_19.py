class Solution:
    def numTrees(self, n: int, cache={}) -> int:
        if n == 0:
            return 1
        if n in cache:
            return cache[n]
        numSubtrees = 0
        for leftSubtreeNodeCount in range(n):
            rightSubtreeNodeCount = n - 1 - leftSubtreeNodeCount
            leftSubtrees = self.numTrees(leftSubtreeNodeCount, cache)
            rightSubtrees = self.numTrees(rightSubtreeNodeCount, cache)
            numSubtrees += leftSubtrees * rightSubtrees
        cache[n] = numSubtrees
        return numSubtrees
