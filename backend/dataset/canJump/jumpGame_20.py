class Solution:
    def canJump(self, nums: List[int]) -> bool:
        ln = len(nums)
        can_reach = 0
        for idx, num in enumerate(nums):
            # i can't reach idx, then I can't move forward
            if idx > can_reach:
                return False
            
            can_reach = max(can_reach, idx + num) 
            #I just passed my destiny
            if can_reach >= ln - 1:
                return True
                    
        
        return False