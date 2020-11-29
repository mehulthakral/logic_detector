import itertools
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def inorder(node):
            if node:
                yield from inorder(node.left)
                yield node.val
                yield from inorder(node.right)

        a, b = itertools.tee(inorder(root))  # two inorder generator
        next(b, None)  # b go on step
        return all(c < d for c, d in zip(a, b))   # compare
