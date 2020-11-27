# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode,
                   max_root_val: int = sys.maxsize,
                   min_root_val: int = -sys.maxsize) -> bool:
        if root:
            # The current node must not statisfy any of the conditions
            if root.val >= max_root_val or root.val <= min_root_val:
                return False
            else: # Check left-subtree and right-subtree
                return (self.isValidBST(root.left, min(max_root_val, root.val), min_root_val)
                        and self.isValidBST(root.right, max_root_val, max(min_root_val, root.val)))
        else: # By default return true   
            return True
