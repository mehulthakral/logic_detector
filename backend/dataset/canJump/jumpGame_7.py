class Solution:
    def canJump(self, nums:List[int])->bool:
        bestJumper,i = nums[0],0
        while i<len(nums) and i<= bestJumper: 
            bestJumper,i = max(bestJumper,i+nums[i]), i+1
        return bestJumper>=len(nums)-1
