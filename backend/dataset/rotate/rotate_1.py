class Solution:    
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        k = k % length
        return self.withConstantSpaceAndOptimized(nums, k)
    
    # Time complexity: O(n), Space complexity: O(1)
    def withConstantSpaceAndOptimized(self, nums, k):
            for index in range(0, k + 1):
                pos = (index + k) % len(nums)
                nums[pos], nums[index] = nums[index], nums[pos]
            return nums
 
