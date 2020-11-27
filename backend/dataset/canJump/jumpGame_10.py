class Solution:
                    
    def canJump(self, nums:List[int])->bool:
        max_reach = nums[0]
        i = 0
        while i <= max_reach and i < len(nums):
            v = nums[i]
            max_reach = max(max_reach, i + v)
            i += 1
        return max_reach >= len(nums) - 1
