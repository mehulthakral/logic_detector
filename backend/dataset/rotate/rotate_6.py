class Solution:
   def rotate(self, nums: List[int], k: int) -> None:
       """
       Do not return anything, modify nums in-place instead.
       """
       n = len(nums)
       k %= n
       count = 0
       curr = 0
       while count < n:
           prev = nums[curr]
           next_ind = curr + k   
           next_ind %= n            
           while True:                
               nums[next_ind], prev = prev, nums[next_ind]
               count += 1
               if next_ind == curr:
                   break
               next_ind += k                
               next_ind %= n                
           curr += 1			
