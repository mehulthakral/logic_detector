from functools import reduce
class Solution:
    def numTrees(self, n: int) -> int:
        return int(round(reduce(lambda a, b: a * ((b + n) / b), list(range(2, n + 1)), 1)))
