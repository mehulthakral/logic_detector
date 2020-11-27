# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if not root:
            return
        
        self.max_sum = 0
        self.neg_sum = float("-inf")
        self.negFlag = False
        def helper(root):
            if not root:
                return 0
            
            left = helper(root.left)
            right = helper(root.right)
            
            self.max_sum = max(self.max_sum, left + root.val + right, root.val, root.val + left, root.val + right)
            
            
            # Handling all -ve values
            self.negFlag |= root.val > 0
            self.neg_sum = max(self.neg_sum, root.val)

            return max(root.val + left, root.val + right, root.val)
            
        helper(root)
            
        if not self.negFlag:
            return self.neg_sum
        return self.max_sum    
