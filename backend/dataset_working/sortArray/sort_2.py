class Solution:
    def sortArray(self, nums:list):
        # Hoare’s Partition Scheme works by initializing two indexes that start at two ends, 
		# the two indexes move toward each other until an inversion is found
        # the partition function will seperate the array by two, smaller than pivot, and greater than pivot
        # and return the final position of the pivot element.
        def partition(nums, left, right):
            if left > right: return
            
            # use the left most element as the pivot element
            pivot_index = left
            pivot=nums[left]
            
            # if the element we are looking for is greater than pivot, then it is on the correct side
            # when right pointer meet the left pointer, we know all the elements are in the correct sides
            # just need to put the pivot to the correct position
            while True:
                while left < right and nums[right] >=pivot:
                    right -=1
            # do the opposite thing to the left hand side
                while left < right and nums[left] <=pivot:
                    left +=1
            # if both of the numbers from the left hand side and the right hand side are on the wron side,
            # we exchange them.
                if left < right:
                    nums[left],nums[right] = nums[right],nums[left]
            # if all the elements are on the correct side, break the loop, just need to insert the pivot now.        
                else:
                    break
            # insert the pivot to the correct position to seperate the array by two
            nums[right],nums[pivot_index] = nums[pivot_index],nums[right]
            return right
        
        def Hoare_quicksort(nums, start, end):
            if end < start: return
            p = partition(nums,start,end)
            Hoare_quicksort(nums,start,p-1)
            Hoare_quicksort(nums,p+1,end)
            
        Hoare_quicksort(nums,0,len(nums)-1)
        return nums
        
