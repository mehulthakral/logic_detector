class Solution:
    def canJump(self, nums: List[int]) -> bool:
        prev = 0
        for i in range(0,len(nums)):
            x = i + nums[i]
            if i <= prev and x > prev:
                prev = x
            if prev >= len(nums)-1:
                return True
        return False
                
        
