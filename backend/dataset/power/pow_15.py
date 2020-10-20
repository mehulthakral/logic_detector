class Solution:
    def myPow(self, x: float, n: int) -> float:
        # x**n == (1/x)**(-n) 
        # by using the property above we can transform the negetive power problem to positive power problem
        # so that we solve the positive power situation, we also solved the negtive power situation.
        if n < 0:
            x = 1/x
            n = -n
        # We solve the positive power here:
        power = 1
        current_product = x
        while n > 0:
            # if n is odd numberm, we need to time x one more time
            if n%2 : 
                power = power * current_product
            current_product = current_product * current_product
            n = n//2
        return power
            
