def isValidBST(self, root: TreeNode, i=(-float('inf'), float('inf'))) -> bool:
        return not root or i[0] < root.val < i[1] and self.isValidBST(root.right, (max(i[0], root.val), i[1])) and self.isValidBST(root.left, (i[0], min(i[1], root.val)))
