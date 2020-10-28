class Solution:
    def myPow(self, x: float, n: int) -> float:
            res = 1 
            temp = abs(n)
            while temp > 0:
                if temp & 1:
                    res = res * x 
                x = x * x 
                temp = temp >> 1 
            if n > 0:
                return res
            else:   
                return 1 / res
