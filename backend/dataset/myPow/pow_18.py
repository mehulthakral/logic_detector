class Solution:
    def myPow(self, x: float, n: int) -> float:
        
        myres = 1
        
        if n == 0: return 1
        elif n < 0: 
            x = 1/x
            n = -n
            
        curProd = x
        k = n
        
        while (k > 0):
            if k%2 == 1: myres *= curProd
            curProd *= curProd
            k //= 2
        return myres

