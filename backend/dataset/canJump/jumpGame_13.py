class Solution:
    def canJump(self, nums: List[int]) -> bool:
# greedy -- reach means last num's maximum reach position, if current index > reach, then means can't reach current position from last number
        reach = 0
        for i, num in enumerate(nums):
            if i > reach:
                return False
            reach = max(reach, i + num)
        return True
