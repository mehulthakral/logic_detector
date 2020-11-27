class Solution:
    def rotate(self, nums:List[int], k: int):
        """
        Do not return anything, modify nums in-place instead.
        """

        
        if len(nums) in [0, 1] or k in [0, len(nums)]:
            return
        k_mod = k % len(nums)
        if len(nums[:-k_mod]) >= len(nums[:k_mod]):
            nums[:] = nums[-k_mod:] + nums[:k_mod] + nums[k_mod:-k_mod]            
        else:
            nums[:] = nums[-k_mod:] + nums[:-k_mod]
        return
