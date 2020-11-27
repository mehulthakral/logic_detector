class Solution:
    def __init__(self):
        self.a = []
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        
        if root is None:
            return
        else:
            left = self.inorderTraversal(root.left)
            self.a.append(root.val)
            right = self.inorderTraversal(root.right)
        return self.a
