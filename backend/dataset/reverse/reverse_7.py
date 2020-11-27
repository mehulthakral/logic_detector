class Solution:
    def reverse(self, x: int) -> int:
        
        sign = 1
        if x < 0:
            sign = -1
            x = -x
        num = str(x)[::-1]
        num = int(num)
        if num < -(2**31) or num > 2**31 - 1:
            return 0
        return -num if sign is -1 else num
