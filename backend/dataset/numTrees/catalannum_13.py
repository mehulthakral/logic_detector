class Solution:
    def numTrees(self, n: int, l = {}) -> int:
        if n==0 or n==1:
            return 1
        if n in l:
            return l[n]
        count = 0
        for i in range(1,n+1):
            count+=self.numTrees(i-1,l)*self.numTrees(n-i,l)
        l[n] = count
        return count
