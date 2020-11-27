class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def inOrderTraversal(root):
            if not root:
                return 0
            inOrderTraversal(root.left)
            stack.append(root.val)
            inOrderTraversal(root.right)
        stack = []
        inOrderTraversal(root)
        return stack == sorted(stack) and stack == sorted(list(set(stack)))
