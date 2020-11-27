class Solution:
    def maxDepth(self, root: TreeNode) -> int:
            def traverse(x):
                if not x:
                    return 0
                return 1 + max(traverse(x.left), traverse(x.right))
            
            return traverse(root)
