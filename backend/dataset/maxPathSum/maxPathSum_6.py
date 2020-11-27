# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode)->int:
        self.ans = -float('inf')
        
        def path(root):
            if not root:
                return 0
            left = max(path(root.left),0)
            right = max(path(root.right),0)
            val = root.val
            self.ans = max(self.ans,val+left+right)
            return val+max(left,right)
        
        path(root)
        return self.ans
