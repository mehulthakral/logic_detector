class Solution:
    # reverses the array arr in place from index s to e
    def reverse_arr_in_place(self, arr, s, e):
        while e > s:
            arr[s], arr[e] = arr[e], arr[s]
            s += 1
            e -= 1
    
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """        
        if k > len(nums):
            k = k % len(nums) 
        self.reverse_arr_in_place(nums, len(nums) - k, len(nums) - 1)        
        self.reverse_arr_in_place(nums, 0, len(nums) - k - 1)
        self.reverse_arr_in_place(nums, 0, len(nums) - 1)
