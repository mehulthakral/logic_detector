class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        res = []
        que = []
        que.append(root)
        lenn = 0
        if root is None:
            return lenn
        while que:
            nodes = []
            for x in range(len(que)):
                node = que.pop(0)
                nodes.append(node.val)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
                    
            lenn += 1
        return lenn
