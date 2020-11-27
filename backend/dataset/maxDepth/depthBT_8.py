class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        left_max = 1 + self.maxDepth(root.left)
        right_max = 1 + self.maxDepth(root.right)
        
        return max(left_max, right_max)
