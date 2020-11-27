class Solution:
    def mySqrt(self, x:int)->int:
        r = x + 1
        while r * r > x: 
            r = int( r - (r * r - x) / (2 * r))
        return r
