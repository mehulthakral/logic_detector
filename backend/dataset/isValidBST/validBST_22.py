class Solution:
    def isValidBST(self, root: TreeNode, low = -float('inf'), high = float('inf')) -> bool:
        if not root:
            return True
        return (low < root.val < high) & (self.isValidBST(root.left, low, root.val)) & (self.isValidBST(root.right, root.val, high))
