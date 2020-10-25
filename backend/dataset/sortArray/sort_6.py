class Solution:
    def sortArray(self, nums):
        count = [0]*100000
        for num in nums:
            count[num+50000] += 1 # count the number of times we see the number
        nums = []
        for i,counter in enumerate(count):
            for _ in range(counter):
                nums.append(i-50000) # this line runs at most n times total
        return nums
    
