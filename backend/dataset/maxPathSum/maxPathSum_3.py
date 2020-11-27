class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = -math.inf
        def dfs(r):
            if not r:
                return 0
            left = dfs(r.left)
            right = dfs(r.right)
            self.ans = max(self.ans,r.val+ left+right)
            return max(0,r.val+ max(left,right))
        _ = dfs(root)
        return self.ans
