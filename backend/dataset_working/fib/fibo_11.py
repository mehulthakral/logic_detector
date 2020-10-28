class Solution:
    # @functools.lru_cache(maxsize=10 ** 6)
    def fib(self, N: int) -> int:  
        if N < 2:
            return N

        return self.fib(N - 1) + self.fib(N - 2)
