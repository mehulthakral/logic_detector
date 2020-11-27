# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        queue = []
        count = 0
        if not root:
            return 0
        queue.append(root)
        while len(queue) > 0:
            size = len(queue)
            while size > 0:
                var = queue.pop(0)
                if var.left is not None:
                    queue.append(var.left)
                if var.right is not None:
                    queue.append(var.right)
                size -= 1 
            count += 1 
        return count  
