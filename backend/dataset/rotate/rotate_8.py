class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums[:] = nums[len(nums) - k :] + nums[:len(nums) - k]
