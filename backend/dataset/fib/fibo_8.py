class Solution:
    def fib(self, N: int) -> int:
        dic = {}
        dic[0], dic[1] = 0, 1
        for i in range(2, N+1):
            dic[i] = dic[i-1] + dic[i-2]
        return dic[N]
