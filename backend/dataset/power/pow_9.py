class Solution:
    def myPow(self, x: float, n: int) -> float:
        def helper(x, n):
            if n == 0:
                return 1
            tmp = helper(x, n // 2)
            if n % 2 == 0:
                return tmp * tmp
            if n % 2 == 1:
                return x * tmp * tmp

        if n >= 0:
            return helper(x, n)

        return 1 / helper(x, -n)
