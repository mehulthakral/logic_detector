class Solution:
    def isUgly(self, num: int) -> bool:
        
        if num == 0:
            # Corner case handle for input 0
            return False
        
        
        given_prime = [2, 3, 5]
        
        for p in given_prime:
        
            while num % p == 0:
                num //= p


        if num == 1:
            return True
        else:
            return False
