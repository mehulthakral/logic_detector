class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_span = 0
        for i, num in enumerate(nums):
            if i + num >= len(nums) - 1:
                return True
            max_span = max(max_span - 1, num)
            if max_span == 0:
                return False
