class Solution:
    def numTrees(self, n: int) -> int:
        if n == 0:
            return 1
        numSubtrees = 0
        for leftSubtreeNodeCount in range(n):
            rightSubtreeNodeCount = n - 1 - leftSubtreeNodeCount
            leftSubtrees = self.numTrees(leftSubtreeNodeCount)
            rightSubtrees = self.numTrees(rightSubtreeNodeCount)
            numSubtrees += leftSubtrees * rightSubtrees
        return numSubtrees
