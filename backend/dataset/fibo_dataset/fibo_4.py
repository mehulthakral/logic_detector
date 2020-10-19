def fib(self, N: int) -> int:
    memo = [0, 1]
    for i in range(2, N+1):
        memo.append(memo[i-1]+memo[i-2])
    return memo[N]