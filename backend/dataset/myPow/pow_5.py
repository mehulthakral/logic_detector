class Solution:
    def myPow(self, x: float, n: int) -> float:
        ## RC ##
        ## APPROACH : RECURSION ##    
        def recurse(n):
            ans = 1
            if(n == 0):
                return 1
            if(n==1):
                return x
            if(n == 2):
                return x * x
            
            if(n%2 == 0):
                ans = recurse(n//2)
                return ans * ans
            if( n%2 == 1):
                ans = recurse(n//2) * recurse((n//2) + 1)
                return ans
            
        if( n < 0 ):
            x = 1/x
            n = -n
        return recurse(n)
