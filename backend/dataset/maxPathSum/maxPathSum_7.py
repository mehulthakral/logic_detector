class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = float('-inf')
        def dfs(root):
            if not root:return 0
            left = dfs(root.left)
            right = dfs(root.right)
            self.ans = max(self.ans,root.val,root.val+left,root.val+right,root.val+left+right)
            return max(root.val,root.val+left,root.val+right)
        dfs(root)
        return self.ans
