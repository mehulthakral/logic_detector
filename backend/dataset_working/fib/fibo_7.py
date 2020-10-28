class Solution:
    def fib(self, N: int) -> int:
        s = [0, 1]
        for i in range(2, N + 1):
            s.append(s[i - 1] + s[i - 2])
        return s[-1] if N > 0 else 0
