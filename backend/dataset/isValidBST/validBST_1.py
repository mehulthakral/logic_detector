class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        curr = root
        stack = []
        while(curr):
            stack.append(curr)
            curr = curr.left
        prev = None
        while(stack):
            top_ele = stack.pop()
            if prev is not None and top_ele.val <= prev:
                return False
            prev = top_ele.val
            next_right = top_ele.right
            while(next_right):
                stack.append(next_right)
                next_right = next_right.left
        return True
