# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if not root.left and not root.right:
            return root.val
        if not root:
            return 0
        
        def solve(node):
            nonlocal res
            l=r=0
            if not node:
                return 0
            if node.left:
                l = max(solve(node.left), 0)
            if node.right:
                r = max(solve(node.right), 0)
            res = max(res, node.val+l+r)
            return node.val + max(l,r)
            
        res = float('-inf')
        solve(root)
        return res
