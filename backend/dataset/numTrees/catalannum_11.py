class Solution:
    def numTrees(self, n: int) -> int:
        memo={}
        return self.sol(n,memo)
     
    def sol(self, n, memo):
        if(n not in memo):
            if(n==1 or n==0): return 1
            if(n==2): return 2
            if(n==3): return 5
            result=0
            mid=n//2
            if(n%2==0):
                for i in range(1,mid+1):
                    result += 2*self.sol(i-1,memo)*self.sol(n-i,memo)
            else:
                mid+=1
                for i in range(1,mid+1):
                    if(i!=mid):
                        result += 2*self.sol(i-1,memo)*self.sol(n-i,memo)
                    else:
                        result += self.sol(i-1,memo)*self.sol(n-i,memo)
            memo[n]=result
        return memo[n]
