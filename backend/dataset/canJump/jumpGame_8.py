class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if 0 not in nums:
            return True
        ladder=0
        n=len(nums)-1
        i=0
        while(i!=n):
            ladder=max(ladder,i+nums[i])   # ladder means the maximum index that can be reached from current index
            if i>=ladder:     # this means we cant go any further (because we can only move further if ladder >current index)
                return False
            i+=1
        return True
