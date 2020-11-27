class Solution:
	def rotate(self, nums: List[int], k: int) -> None:
		"""
		Do not return anything, modify nums in-place instead.
		"""
		d = deque(nums)
		d.rotate(k)
		nums.clear()
		while d:
			nums.append(d.popleft())
