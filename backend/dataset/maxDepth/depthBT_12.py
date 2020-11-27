class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: 
            return 0
        
        left_level = self.maxDepth(root.left) + 1 
        right_level = self.maxDepth(root.right) + 1 
        
        return max(left_level, right_level) 
