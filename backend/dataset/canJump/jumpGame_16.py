class Solution:
    def canJump(self, nums: List[int]) -> bool:
        p=nums[0] #index of farthest potion can reach for now
        for i in range(1,len(nums)):
            if p>=i:
                p = max(p, nums[i]+i)
        return p>=len(nums)-1
            
