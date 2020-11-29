import sys
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.answer =  - sys.maxsize - 1
        def dfs(node):
            if not node:
                return 0
            left_sub_tree = dfs(node.left)
            right_sub_tree = dfs(node.right)
            self.answer = max(self.answer , left_sub_tree + right_sub_tree + node.val)
            return max(0 , node.val + max(left_sub_tree , right_sub_tree))
        dfs(root)
        return self.answer
