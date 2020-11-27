class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        order = []
        if root is None:
            return order
        
        level = [root]
        while len(level) > 0:
		    # Add the new level to the final results.
            order.append([node.val for node in level])
			
			# Clear our level cache, and get all the children of the current level.
            parent = level
            level = []
            
            for node in parent:
                if node.left:
                    level.append(node.left)
                if node.right:
                    level.append(node.right)
            
        return order
