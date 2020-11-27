class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def check(node: TreeNode):
            (lps, ls) = check(node.left) if node.left else (0, float('-inf'))
            (rps, rs) = check(node.right) if node.right else (0, float('-inf'))
            return max(lps + node.val, rps + node.val, node.val), max(ls, rs, lps + node.val, rps + node.val, lps + rps + node.val, node.val)
        return check(root)[1]
