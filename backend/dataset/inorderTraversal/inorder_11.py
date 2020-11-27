class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def rec(root):
            if not root:
                return
            rec(root.left)
            ans.append(root.val)
            rec(root.right)
        rec(root)
        return ans
