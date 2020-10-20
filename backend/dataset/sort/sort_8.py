class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        nums = [[num] for num in nums]

        def merge(l1, l2):
            i = 0
            j = 0
            new = []
            
            while i < len(l1) and j < len(l2):
                if l1[i] < l2[j]:
                    new.append(l1[i])
                    i += 1
                else:
                    new.append(l2[j])
                    j += 1
                    
            while i < len(l1):
                new.append(l1[i])
                i += 1
                
            while j < len(l2):
                new.append(l2[j])
                j += 1
                
            return new

        
        while len(nums) > 1:
            new = []
            for i in range(0, len(nums), 2):
                if i + 1 < len(nums):
                    new_arr = merge(nums[i], nums[i+1])
                    new.append(new_arr)
                else:
                    new.append(nums[i])
            nums = new
            
        return nums[0]
