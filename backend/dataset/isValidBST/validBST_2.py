class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        _, _, is_valid = self.recur(root)
        return is_valid
    
    def recur(self, root):
        if not root:
            return float('inf'), float('-inf'), True
        min_left, max_left, is_valid_left = self.recur(root.left)
        min_right, max_right, is_valid_right = self.recur(root.right)

        if root.val < min_right and root.val > max_left:
            curr_is_valid = is_valid_left and is_valid_right
            left_min = min(min_left, root.val)
            right_max = max(max_right, root.val)
        else:
            curr_is_valid = False
            left_min = float('inf')
            right_max = float('-inf')
        return left_min, right_max, curr_is_valid
