class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        output =[]
        def inorderTraversalHelper(root):
            if not root:
                return None
            inorderTraversalHelper(root.left)
            output.append(root.val)
            inorderTraversalHelper(root.right)
        inorderTraversalHelper(root)
        return output
