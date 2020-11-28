import sys
class Solution:
	def strStr(self, haystack, needle):
		def f(c):
			return ord(c)-ord('A')

		n, h, d, m = len(needle), len(haystack), ord('z')-ord('A')+1, float("inf")
		if n > h: return -1
		nd, hash_n, hash_h = d**(n-1), 0, 0   
		for i in range(n):
			hash_n = (d*hash_n+f(needle[i]))%m
			hash_h = (d*hash_h+f(haystack[i]))%m            
		if hash_n == hash_h: return 0        
		for i in range(1, h-n+1):
			hash_h = (d*(hash_h-f(haystack[i-1])*nd)+f(haystack[i+n-1]))%m    # e.g. 10*(1234-1*10**3)+5=2345
			if hash_n == hash_h: return i
		return -1
