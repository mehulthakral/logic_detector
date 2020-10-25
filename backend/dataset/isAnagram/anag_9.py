from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ## RC ##
        ## APPROACH : Counter ##
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(1) ##
        return Counter(s) == Counter(t)

