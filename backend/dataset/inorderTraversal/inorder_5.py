class Solution:
    def inorderTraversal(self, node: TreeNode) -> List[int]:
        if node is None:
            return []

        left_children = self.inorderTraversal(node.left)
        right_children = self.inorderTraversal(node.right)

        return [*left_children, node.val, *right_children]