class Solution:
    def fib(self, N: int) -> int:
        f = (0, 1)
        if N == 0:
            return f[0]
        elif N == 1:
            return f[1]
        else:
            for _ in range(2, N + 1):
                f += (f[-2] + f[-1],)

        return f[-1]
