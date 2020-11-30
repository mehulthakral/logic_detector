from typing import List
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        interval = [0, 0]
        if n <= 1:
            return True
        
        while True:
            can_reach = -1
            
            for i in range(interval[0], interval[1] + 1):
                can_reach = max(can_reach, i + nums[i])
            
            if can_reach >= n - 1:
                return True
            
            interval = [interval[1] + 1, can_reach]
            
            if interval[0] > interval[1]:
                return False
        
        assert(False)