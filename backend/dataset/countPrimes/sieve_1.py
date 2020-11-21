class Solution:
	def countPrimes(self, n: int) -> int:
		if n <= 2:
			return 0

		table = [True]*n
		table[0], table[1] = False,False

		i = 2
		while i*i < n:
			if table[i]:
				for j in range(i*i, n, i):
					table[j] = False
			i+=1

		return sum(table)
