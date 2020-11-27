class Solution:
    def nodeMax(self, node):
        if not node:
            return 0
        else:
            lmax, rmax = self.nodeMax(node.left), self.nodeMax(node.right)
            self.res = max(self.res, node.val + lmax + rmax)
            return max(node.val + max(lmax, rmax), 0)
    def maxPathSum(self, root: TreeNode) -> int:
        self.res = root.val
        self.nodeMax(root)
        return self.res
