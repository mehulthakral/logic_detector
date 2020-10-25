class Solution(object):
    def myPow(self, x, n):
        """
        Implementation of pow(x, n), which calculates x raised to the power n (i.e. xn)
        Algorithm:
            x raised to n = (x raised 2) raised n/2 if n is even
            and x raised to n = x times {(x raised 2) raised (n-1)/2} if n is odd
        """
        
        def raiseto(base=x, exponent=abs(n)):
            if exponent == 0:
                return 1
            elif exponent % 2 == 0:
                return raiseto(base * base, exponent // 2)
            else:
                return base * raiseto(base * base, (exponent - 1) // 2)

        raised = raiseto()

        return float(raised) if n >=0 else 1/raised
        
