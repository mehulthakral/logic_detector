class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self._max = -float('inf')
        def traverse(node):
            if not node: return 0
            left = traverse(node.left)
            right = traverse(node.right)
            # we keep traversing upwards
            local_max = max(node.val, node.val + max(left, right))
            # we cross the path and we are done
            self._max = max(self._max, local_max, node.val+left+right)
            return local_max
        return max(traverse(root), self._max)
