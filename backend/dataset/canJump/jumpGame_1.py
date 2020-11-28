from typing import List
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if nums[0] == 0 and len(nums) > 1:
            return False
        
        # maximum_dis stands for the maximum distance we can reach so far 
        maximum_dis = 0
        for i in range(len(nums)):
            # If the current index is beyond the maximum distance we can jump to, directly return False
            if i > maximum_dis:
                return False
            
            # If maximum_dis larger or equal to the last index, it means we can reach the last index for sure
            if maximum_dis >= len(nums) - 1:
                return True
            
            # Update the maximum_dis
            if nums[i] + i > maximum_dis:
                maximum_dis = nums[i] + i
