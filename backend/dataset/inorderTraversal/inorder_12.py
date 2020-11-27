class Solution:
	def inorderTraversal(self, root: TreeNode) -> List[int]:
		if not root:
			return
		
		# inorder: L-V-R
		result:List[int] = []
		stack:List[int] = []
			
		while True:
			if root:
				stack.append(root)
				root = root.left
			else:
				if len(stack)==0:
					break
				else:
					root = stack.pop()
					result.append(root.val)
					root = root.right
				
		return result
