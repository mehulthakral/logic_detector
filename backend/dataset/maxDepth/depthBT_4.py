class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        
        if not root.left:
            return right + 1
        
        if not root.right:
            return left + 1
        
        return max(left, right) + 1
