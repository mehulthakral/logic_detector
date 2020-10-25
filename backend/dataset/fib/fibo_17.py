class Solution:
    def fib(self, N: int) -> int:
        if N < 2:
            return N
        
        p1 = 1
        p2 = 1
        
        for i in range(2, N):
            temp = p1
            p1 += p2
            p2 = temp
            
        return p1
