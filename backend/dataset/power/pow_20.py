import math

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if x == 0 or x == 1 or n == 1:
            return x
        
        if n == 0:
            return 1

        if n < 0:
            x = 1.0/x

        result = self.doPow(x, abs(n))
        
        return result
    
    def doPow(self, x, n):
        # check boundary condition
        if n == 1:
            return x
        
        # compute the power value
        powerVal = math.pow(x, 2)
        
        # recurse
        result = self.doPow(powerVal, n/2)
        
        # handle odd n case
        if n % 2 == 1:
            result *= x
        
        return result
