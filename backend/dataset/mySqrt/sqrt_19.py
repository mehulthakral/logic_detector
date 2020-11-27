## Newton method
class Solution:
    def mySqrt(self, x: int) -> int:
        num = x
        while num * num > x:
            num = (num + x//num) // 2
        return num
        

