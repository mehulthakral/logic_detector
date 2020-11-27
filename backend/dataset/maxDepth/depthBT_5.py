class Solution:
    def maxDepth(self, node: TreeNode) -> int:
        if node is None:
            return 0

        return max(self.maxDepth(node.left) + 1, self.maxDepth(node.right) + 1)