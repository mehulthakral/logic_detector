class Solution:
    def sortArray(self, nums:list):

        def partition(nums, left, right):
            if left > right: return
            
            # use the middle  element as the pivot
            pivot_index = left + (right-left)//2
            pivot=nums[pivot_index]

            while left<=right:
                while left <= right and nums[left] <pivot:
                    left +=1
                while left <= right and nums[right] >pivot:
                    right -=1
                if left <= right:
                    nums[left],nums[right] = nums[right],nums[left]
                    left +=1
                    right -=1
                else:
                    break
            return (left,right)
        
        def Hoare_quicksort(nums, start, end):
            if end < start: return
            p = partition(nums,start,end)
            Hoare_quicksort(nums,start,p[1])
            Hoare_quicksort(nums,p[0],end)
            
        Hoare_quicksort(nums,0,len(nums)-1)
        return nums
        
