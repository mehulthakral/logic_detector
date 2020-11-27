# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        
        max_depth = 0
        
        if not root:
            return max_depth
        
        if not root.left and not root.right:
            return max_depth + 1
            
        max_depth = max(self.current_max_depth(root.left, 1), self.current_max_depth(root.right, 1))
        
        return max_depth
    
    def current_max_depth(self, node: TreeNode, current_max_depth_value: int) -> int:
        
        current_max_depth_value += 1
        
        if not node:
            return current_max_depth_value
        
        if not node.left and not node.right:
            return current_max_depth_value
        
        current_max_depth_value = max(self.current_max_depth(node.left, current_max_depth_value), self.current_max_depth(node.right, current_max_depth_value))
        
        return current_max_depth_value
