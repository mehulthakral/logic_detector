class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0 or x == 1.0:
            return 1.0
        if x == 0:
            if n < 0:
                return float('inf')
            else:
                return 0.0
        
        if n < 0:
            x, n = 1/x, -n
        
        res, num, power = 1.0, x, n
        while power != 1:
            if power%2 == 0:
                num = num*num
                power /= 2
            else:
                res *= num
                power -= 1
        
        return res*num
