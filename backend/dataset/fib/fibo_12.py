class Solution:
	def fib(self, N: int) -> int:
		def dfs(n):
			if n not in memo: memo[n] = dfs(n-1)+dfs(n-2)            
			return memo[n]
			
		memo = {0:0, 1:1}
		return dfs(N)
