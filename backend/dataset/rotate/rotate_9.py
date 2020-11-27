import math

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
		
		# Remove redundant passes
        shift = k % n
        gcd = math.gcd(shift, n)
        
        for j in range(gcd):
            i, temp = shift + j, nums[j]
            while i != j:
                nums[i], temp, i = temp, nums[i], (i + shift) % n

            nums[i] = temp
        
