# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def recursive(node, li):
            if node:
                recursive(node.left, li)
                li.append(node.val)
                recursive(node.right, li)
                
            return li
        
        return recursive(root, res)
