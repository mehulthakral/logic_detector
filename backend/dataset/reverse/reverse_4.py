class Solution:
    def reverse(self, x: int) -> int:
        a = list(str(abs(x)))
        b = 0
        for i in range(len(a)):
            b += int(a[i]) * (10 ** i)
        
        if b < -(2**31) or b > ((2**31) - 1):
            return 0
        
        if x < 0:
            return (-1) * b
        else:
            return b