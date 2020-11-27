class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        
        if not root:
			# Base case:
            # Empty tree or empty leaf node
            return 0
        
        else:
            # General case
            left = self.maxDepth( root.left )
            right = self.maxDepth( root.right )
            
            return max(left, right)+1
