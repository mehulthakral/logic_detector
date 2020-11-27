# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def travel(node):
            if not node:
                return 0
            l=r=0
            if node.left:
                l = travel(node.left)
            if node.right:
                r = travel(node.right)
            return 1+max(l,r)
        return travel(root)
