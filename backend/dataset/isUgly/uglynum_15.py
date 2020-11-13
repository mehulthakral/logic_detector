class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False

        primes = [2, 3, 5]
        for prime in primes:
            while num % prime == 0:
                num /= prime
            if num == 1: 
                return True
        return False
