class Solution:
    def numTrees(self, n: int) -> int:
        return self.count_bsts(1, n, {})
			
    def count_bsts(self, min_val: int, max_val: int, memo: dict) -> int:
        if min_val >= max_val:
            return 1

        elif (min_val, max_val) in memo:
            return memo[(min_val, max_val)]

        bsts_count = 0
        for val in range(min_val, max_val + 1):

            left_subtrees_count = self.count_bsts(min_val, val - 1, memo)
            right_subtrees_count = self.count_bsts(val + 1, max_val, memo)

            bsts_count += left_subtrees_count * right_subtrees_count

        memo[(min_val, max_val)] = bsts_count
			
        return bsts_count
	
