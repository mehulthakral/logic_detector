class Solution:
    def fib(self, N: int) -> int:
        if N < 2: return N
        a, b = 0, 1
        for _ in range(N-1):
            c = a+b
            a, b = b, c
        return c
