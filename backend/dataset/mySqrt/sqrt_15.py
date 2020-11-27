class Solution:
	def mySqrt(self, x: int) -> int:
		if x==1: return 1
		low=1
		high=x//2
		while low+1<high:
			mid=(high+low)//2
			if mid*mid==x:
				return mid
			elif mid*mid >x:
				high=mid
			else:
				low=mid
		if high*high>x:
			return low
		return high