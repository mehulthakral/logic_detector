class Solution:
    def myPow(self, x, n, r=1) -> float:
        x, n = n < 0 and 1 / x or x, abs(n)
        return self.myPow(x * x, n // 2, r * (not n % 2 or x)) if n else r
