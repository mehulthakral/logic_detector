import sys
class Solution:
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False
        if n == 1:
            return True
        multipliers = [30, 15, 10, 8, 6, 5, 4, 3, 2]
        for mult in multipliers:
            for _ in range(sys.maxsize):
                if n.__mod__(mult) == 0:
                    n = divmod(n, mult)[0]
                    if n == 1:
                        return True
                else:
                    break

        return False
