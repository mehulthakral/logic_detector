# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        else:
            ans = []
            x = [root]
            while x:
                c = x.pop()
                if isinstance(c, TreeNode):
                    if c.right:
                        x.append(c.right)
                    x.append(c.val)
                    if c.left:
                        x.append(c.left)
                else:
                    ans.append(c)
            return ans
