class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
	
        if len(nums) <=1: return nums
        less , greater , base = [] , [] , nums.pop()
        for i in nums:
            if i < base: less.append(i)
            else: greater.append(i)
        return self.sortArray(less) + [base] + self.sortArray(greater)
