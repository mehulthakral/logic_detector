class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        max_depth = 0
        L = [root]
        while L:
            max_depth += 1
            L_next = []
            for n in L:
                if n.left != None:
                    L_next.append(n.left)
                if n.right != None:
                    L_next.append(n.right)
            L = L_next
        return max_depth
