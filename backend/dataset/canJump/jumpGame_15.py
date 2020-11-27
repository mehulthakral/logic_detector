class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxdis = 0  # max distance can be reached after i iteration
        for i in range(len(nums)):
            if i > maxdis: return False #if position i can not be reached, False
            maxdis = max(nums[i]+i, maxdis) # max distance may or may not be updated
        return True
