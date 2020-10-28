class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0 or abs(x) == 1: return 1 if x == 1 else 1 - 2*(n % 2)
        p, T = 1, 1E5
        for i in range(abs(n)):
            p *= x
            if (abs(p) < 1/T and n > 0) or (abs(p) > T and n < 0): return 0
        return p if n > 0 else 1/p
		