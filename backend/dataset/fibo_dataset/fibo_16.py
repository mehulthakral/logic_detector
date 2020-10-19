class Solution:
    def fib(self, N: int) -> int:
        curr = 1
        prev = 0

        if N == 0:
            return prev
        elif N==1:
            return curr
        else:
            for i in range(N-1):
                prev, curr = curr, curr+prev

        return curr
