class Solution:
    def mySqrt(self, x: int) -> int:
        a = x            
        while int(a) * int(a) > x:
            a -= (a * a - x) / (2 * a)            
        return int(a)
