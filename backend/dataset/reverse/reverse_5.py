class Solution:
    def reverse(self, x: int) -> int:
        rev = int(str(abs(x))[::-1])
        i = -rev if x < 0 else rev
        if i < -2**31 or i > 2**31-1:
            return 0
        return i
