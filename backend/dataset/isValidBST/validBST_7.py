# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        #Simply using a recursive approach to check the value
        # left child is < above parent & right child is > above parent...
    def isValidBST(self, tree: TreeNode) -> bool:
        def are_keys_in_range(tree, low_range = float('-inf'),high_range = float('inf')):
            if tree and tree.val == high_range:
                return False
            elif not tree:
                return True
            elif not low_range < tree.val < high_range: #doesn't hold
                return False
            
            return (are_keys_in_range(tree.left,low_range,tree.val) and are_keys_in_range(tree.right,tree.val,high_range))
        return (are_keys_in_range(tree))
    
