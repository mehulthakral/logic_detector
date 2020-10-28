class Solution:
    def myPow(self, x: float, n: int) -> float:
        result = 1

        
        if n<0:
            x = 1/x
            n=-n
        power = n

        
        while power:
            if power&1:
                result = result*x
            x = x*x
            power = power >>1
            
        return result
