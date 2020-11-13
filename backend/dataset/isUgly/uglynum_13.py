class Solution:
    def isUgly(self, num):
            def f(n, p):
                while not n % p:
                    n = n // p           
                return n
            
            P = [num, 2, 3, 5]
            return reduce(f, P) == 1 if num > 0 else False
