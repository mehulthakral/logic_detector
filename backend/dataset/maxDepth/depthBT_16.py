class Solution:
	def maxDepth(self, root: TreeNode) -> int:
		if not root:
			return 0
		q = [root]
		max_depth = 0
		while q:
			size = len(q)
			max_depth+=1
			while size:
				front = q.pop(0)
				size-=1

				if front.left:
					q.append(front.left)
				if front.right:
					q.append(front.right)

		return max_depth
