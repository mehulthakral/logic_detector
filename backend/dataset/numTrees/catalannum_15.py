import math
class Solution:
    def numTrees(self, n: int) -> int:
        num = math.factorial(2*n)
        denom = math.factorial(n)*math.factorial(n+1)
        return num // denom
