class Solution:
    def isUgly(self, num: int) -> bool:
        if num < 1: return False
        for factor in [2,3,5]:
            while num % factor == 0:
                num //= factor
        return num == 1
