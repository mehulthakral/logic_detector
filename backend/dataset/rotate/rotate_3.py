from collections import deque 
from typing import List
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        d = deque(nums)
        d.rotate(k)
        nums.clear()
        while d:
            nums.append(d.popleft())
