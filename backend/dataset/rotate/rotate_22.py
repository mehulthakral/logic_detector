class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k<len(nums):
            for i in range(0,k):
                e=nums.pop()
                nums.insert(0,e)
        elif k>len(nums):
            k=k%len(nums)
            for i in range(0,k):
                e=nums.pop()
                nums.insert(0,e)
        else:
            pass
        
