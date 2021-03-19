from dataset_server import TreeNode
class Solution:
    def isValidBST(self, root:TreeNode, left = float('-inf'), right = float('inf'))->bool:
        return not root or left < root.val < right and self.isValidBST(root.left, left, root.val) and self.isValidBST(root.right, root.val, right)