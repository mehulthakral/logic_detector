class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = float("-inf")

        def postorder(root):
            if not root:  return 0

            left_val, right_val = max(0, postorder(root.left)), max(0, postorder(root.right))
            self.ans = max(self.ans, (root.val + left_val + right_val))
            return max((root.val + left_val), (root.val + right_val))

        postorder(root)
        return self.ans

