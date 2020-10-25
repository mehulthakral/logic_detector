class Solution:
    def fib(self, N: int) -> int:
        f = [0, 1]
        if N == 0:
            return f[0]
        elif N == 1:
            return f[1]
        else:
            for i in range(2, N + 1):
                f.append(f[i-2] + f[i-1])

        return f[-1]
