class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def helper(node, depth):
            if not node:
                return depth
            return max(helper(node.left, depth + 1), helper(node.right, depth + 1))
        return helper(root, 0)
