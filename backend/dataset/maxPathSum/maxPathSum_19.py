class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        Max = float("-inf")
        def maxPath(root):
            nonlocal Max
            if not root:
                return float("-inf")
            left1= maxPath(root.left)
            right1= maxPath(root.right)
            temp = max(root.val, root.val + left1, root.val + right1)
            Max = max(Max, temp, left1+right1+root.val)
            return temp
        res = maxPath(root)
        return Max if Max != float("-inf") else 0
