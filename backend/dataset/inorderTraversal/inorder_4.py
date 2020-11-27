class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        return self.helper(root, [])
        
    
    def helper(self, node, acc):
        if not node: return acc
        if node.left:
            self.helper(node.left, acc)
        
        acc.append(node.val)
        
        if node.right:
            self.helper(node.right, acc)
        
        return acc
