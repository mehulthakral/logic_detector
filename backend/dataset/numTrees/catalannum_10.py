class Solution:
    def numTrees(self, n: int) -> int:
            facts = [1]
            for i in range(2*n):
                facts.append((i + 1)*facts[-1])
            return facts[-1] // (facts[n] * facts[n + 1])
