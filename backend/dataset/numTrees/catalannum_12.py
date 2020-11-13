class Solution:
    def numTrees(self, n: int) -> int:
        ar=[0]*(n+1)
        ar[0]=1
        for i in range(1,n+1):
            for j in range(i):
                ar[i]=ar[i]+(ar[j]*ar[i-j-1])
        return ar[n]