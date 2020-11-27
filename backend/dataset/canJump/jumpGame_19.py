class Solution:
    def canJump(self, nums: List[int]) -> bool:
        x = 1
        for y in nums[:-1]:
            x = max(x-1, y)
            if x == 0:
                return False
        return True
