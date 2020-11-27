# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def helper(root, lower=float("-inf"), upper=float("inf")):
        
            if not root:
                return True
            if lower < root.val < upper:
                if helper(root.left, lower, root.val) and helper(root.right, root.val, upper):
                    return True
                else:
                    return False
            else:
                return False

        return helper(root)  
