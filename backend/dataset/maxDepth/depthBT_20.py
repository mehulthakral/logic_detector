class Solution:
       
    def maxDepth(self, root: TreeNode) -> int:
        
        self.tree_depth = 0
        
        def helper( node: TreeNode, depth: int):
            
            if not node:
				# Base case
				# Empty node or empty tree
                return
        
            if not node.left and not node.right:
				# Base case
				# Update max depth when reach leaf node
                self.tree_depth = max( self.tree_depth, depth )
            
            else:
				# General case
				# Keep DFS down to next level
                helper( node.left, depth + 1)
                helper( node.right, depth + 1)
        
        # ------------------------------------------------
        helper( node = root, depth = 1 )
        return self.tree_depth
