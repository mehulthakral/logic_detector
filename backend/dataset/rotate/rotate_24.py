class Solution:
    def rotate(self,nums:List[int], k:int)->None:
        if len(nums) == 0: return []
        if len(nums) == k: return nums
        if k > len(nums):
            rotations = k % len(nums)
        else:
            rotations = k
        return nums[-rotations:] + nums[:-rotations]
