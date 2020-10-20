class Solution:
    def isAnagram(self, s, t):
		return Counter(s)==Counter(t)
