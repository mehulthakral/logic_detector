class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # cover simple cases
        if len(nums) == 1:
            return True
        elif nums[0] == 0:
            return False
        # process from right to left and keep track of
        # how many steps are need to get to the end
        min_steps_needed = 0
        for num in reversed(nums[:-1]):
			# we need at least one step to get from one index to the next one
            min_steps_needed += 1
			# if we have least that number at the current index, we can reset the step counter
            if num >= min_steps_needed:
                min_steps_needed = 0
		# if we do not need extra steps, return True (`min_steps_needed = 0`) and 
		# otherwise False (`min_steps_needed > 0`)
        return min_steps_needed == 0
