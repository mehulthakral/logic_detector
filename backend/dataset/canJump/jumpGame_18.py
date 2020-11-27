class Solution:
    def canJump(self, nums: List[int]) -> bool:
            
        max_ind = 0     
        
        for i, num in enumerate(nums):
            if max_ind >= len(nums)-1:
                return True
            
            if num==0:
                if max_ind<=i:
                    return False
            
            max_ind = max(i+num, max_ind)
