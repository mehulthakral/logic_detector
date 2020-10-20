class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # Merge Sort
        
        # merge takes two sorted array, and return the merged sorted array
        # Leetcode #88
        def merge(left, right):
            l = len(left)-1
            r = len(right)-1
            end = l+r+1
            
            for _ in range(r+1):
                left.append(None)
                
            while l>=0 and r>=0:
                if left[l] >=right[r]:
                    left[end]=left[l]
                    l-=1
                else:
                    left[end]=right[r]
                    r-=1
                end-=1
            if l ==-1:
                for _ in range(r+1):
                    left[_]=right[_]
            
            return left
        
        # if there is only one number, return the number
        # if both left and right are sorted arrays, merge these two
        if len(nums)<=1: return nums
        mid = len(nums)//2
        leftarray = self.sortArray(nums[:mid])
        rightarray= self.sortArray(nums[mid:])
        return merge(leftarray,rightarray)
        
    
