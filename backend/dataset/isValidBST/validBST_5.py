class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root: return True
        
        prev = float("-inf")
        
        for node in self.inOrder(root):
            if node.val <= prev: return False
            prev = node.val
        
        return True
        
    def inOrder(self, node):
        if not node: return

        yield from self.inOrder(node.left)
        yield(node)
        yield from self.inOrder(node.right)
