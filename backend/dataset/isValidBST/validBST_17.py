# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.recurse(root, -float('inf'), float('inf'))
        
    
    def recurse(self, node, lo, hi): 
        if not node: 
            return True 
        
        out = True 
        if node.left: 
            new_lo, new_hi = lo, min(node.val, hi)
            out = out and new_lo < node.left.val and node.left.val < new_hi and self.recurse(node.left, new_lo, new_hi)
            
        if node.right: 
            new_lo, new_hi = max(lo, node.val), hi 
            out = out and new_lo < node.right.val and node.right.val < new_hi and self.recurse(node.right, new_lo, new_hi) 
        
        return out 
