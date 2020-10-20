class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ## RC ##
        ## APPROACH : Counter ##
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(1) ##
        return collections.Counter(s) == collections.Counter(t)

