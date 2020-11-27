class Solution:
    def canJump(self, nums: List[int]) -> bool:
        N = len(nums)
        if N <= 1:
            return True
        j = N - 1  # smallest OK index
        for i in range(N-2, -1, -1):
            if i + nums[i] >= j:
                j = i
        return j == 0
