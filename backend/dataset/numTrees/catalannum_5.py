class Solution:
    def numTrees(self, n: int) -> int:
		# dp: store the result(status) in dictionary from the bottom, so we don't have to calculate every time
        dp = {}
        dp[0] = 1

        # num : every size of the tree in range(1, n + 1)
        for num in range(1, n + 1):
            res = 0
            
			# choose pivot i, the total result = left * right
            for i in range(1, num + 1): 
                res = res + dp[i - 1] * dp[num - i]
            dp[num] = res
        return dp[n]
