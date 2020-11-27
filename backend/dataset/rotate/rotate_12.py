class Solution:
    def rotate(self, nums:List[int], k:int)->None:
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nums1 = nums[:len(nums)-k]
        nums2 = nums[ len(nums)-k: ]
        
        k=k%len(nums)
        
        for i in range(len(nums2)):
            nums[i] =  nums2[i]
        for i in range(len(nums1)):
            nums[ k+i ] = nums1[i] 
        
        return nums
