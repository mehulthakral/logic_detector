class Solution:
    def numTrees(self, n: int) -> int:
        self.table = [-1] * (n+1)
        self.table[0] = 1
        return self.numTreesRec(n)
        
    def numTreesRec(self, n):
        if self.table[n] != -1:
            return self.table[n]
        total = 0
        for m in range(n):
            total += (self.numTreesRec(n-1-m) * self.numTreesRec(m))
        self.table[n] = total
        return total
