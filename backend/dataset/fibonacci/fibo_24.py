from scipy import constants as c

class Solution:
    def fib(self, N: int) -> int:
        return int((c.golden ** N + 1) / 5 ** 0.5)
