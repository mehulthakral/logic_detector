class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        _, m = self._maxPathSum(root)
        return m

    def _maxPathSum(self, tree):
        if tree == None:
            return (float('-inf'), float('-inf'))

        lsb, ls = self._maxPathSum(tree.left)
        rsb, rs = self._maxPathSum(tree.right)
        val = tree.val

        cb = max(lsb, rsb)
        b = max(cb + val, val)
        r = max(lsb + val + rsb, b)
        m = max(ls, rs, r)

        return (b , m)
