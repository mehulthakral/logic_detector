class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        if n == 0 : return
        if k>n : k = k%n
        
        # extend the list
        for i in range(n-k):
            nums.append(0)
        
        #fill the extension
        for i in range(n-k):
            nums[i+n] = nums[i]
        
        #rotate
        for i in range(n):
            nums[i] = nums[i+n-k]
        
        #cut down the list
        i = n-k
        while(i>0):
            nums.pop()
            i -= 1
