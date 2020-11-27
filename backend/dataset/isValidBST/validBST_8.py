class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        self.answer = True
        
        def dfs(root, left, right):
            if root:
                if left >= root.val or root.val >= right:
                    self.answer = False
                    return
                dfs(root.left, left, root.val)
                dfs(root.right, root.val, right)
        dfs(root, float("-inf"), float('inf'))
        return self.answer
