class Solution:
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False
        if n == 1:
            return True
        multipliers = [2, 3, 5]
        for mult in multipliers:
            for _ in range(1000):
                if n.__mod__(mult) == 0:
                    n = divmod(n, mult)[0]
                    if n == 1:
                        return True
                else:
                    break

        return False
        
