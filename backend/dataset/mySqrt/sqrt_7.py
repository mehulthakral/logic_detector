class Solution:
	def mySqrt(self, x: int) -> int:
		if x == 1:
			return 1

		lower = 0
		upper = x // 2 if x > 5 else x
		middle = (lower + upper) // 2

		while True:
			if middle * middle == x:
				return middle
			elif middle * middle > x:
				upper = middle
			else:
				lower = middle

			if (lower + upper) // 2 == middle:
				return middle
			middle = (lower + upper) // 2