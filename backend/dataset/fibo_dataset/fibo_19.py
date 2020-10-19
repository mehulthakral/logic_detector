class Solution:
    def fib(self, N: int) -> int:
        a,b = 0 ,1
        n = 2
#special case is when N is 0 or 1:
        if N ==0:
            return 0
        if N ==1:
            return 1
#run while loop to do the math
        while n<=N:
            rst = a + b
            a,b = b , a+b
            n +=1
        return(rst)
