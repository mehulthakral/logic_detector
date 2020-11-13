class Solution:
    def sortArray(self, nums:list):
        def heapify(nums, n, i):
            # 
            if i > n: return
            largest = i
            l = 2*i+1
            r = 2*i+2

            if l < n and nums[l] > nums[largest]:largest = l
            if r < n and nums[r] > nums[largest]:largest = r
            # swap the largest element with the parent node of the tree
            if largest != i: 
                nums[i], nums[largest] = nums[largest],nums[i]
                heapify(nums, n, largest) # 
        
        
        def build_heap(nums):
            n = len(nums)
            lastNode = n-1
            lastParent = (lastNode-1)//2
            for i in range(lastParent+1)[::-1]:
                heapify(nums, n, i)
        build_heap(nums)

        def heap_sort(nums):
            n = len(nums)
            for i in range(n)[::-1]:
                nums[0],nums[i]=nums[i],nums[0]
                heapify(nums, i, 0)
        heap_sort(nums)

        return nums
