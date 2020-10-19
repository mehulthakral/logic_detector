def sortArray(self, nums: List[int]) -> List[int]:
    # radix sort implementation, O(n) time complexity, where n == len(nums)
    nums = [num + 50000 for num in nums] # unsorted array
    A = [0] * len(nums) # each loop's sorted array
    I = [0] * 10 # set up index array
    for i in range(6): # because there are 6 digits
        for num in nums:
            I[num // (10 ** i) % 10] += 1 # find out how many occurrences of each digit
        I = list(itertools.accumulate(I, lambda a, b: a + b)) # calculate the prefix sum
        for j in reversed(range(len(nums))):
            # invariant: The list is sorted at digit [j + 1:], waiting to be sorted at digit j
            A[I[nums[j] // (10 ** i) % 10] - 1] = nums[j] # update A from the back
            I[nums[j] // (10 ** i) % 10] -= 1 # update I at that position
        nums[:], I[:] = A[:], [0] * 10 # copy result to nums to begin new loop, and refresh I
    return [num - 50000 for num in nums]
