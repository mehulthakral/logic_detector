class Solution:
    def inorderTraversal(self, root:TreeNode)->List[int]:
        return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right) if root else []
