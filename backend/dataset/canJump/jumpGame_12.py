class Solution:
    def canJump(self, nums:List[int])->bool:
        required_length = 1

        for i in range(len(nums) - 2, -1, -1):
            if nums[i] > 0 and nums[i] >= required_length:
                required_length = 1
            else:
                required_length += 1


        if required_length == 1:
            return True

        return False