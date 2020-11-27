class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k=k%n
        nums.reverse()
        a=reversed(nums[k:])
        b=reversed(nums[:k])
        nums.clear()
        nums.extend(b)
        nums.extend(a)
