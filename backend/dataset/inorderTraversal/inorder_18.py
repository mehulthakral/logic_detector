class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        curr = root
        res = []
        while curr:
            if curr.left:
                pre = curr.left
                while pre.right and pre.right!=curr:
                    pre = pre.right
                if pre.right == curr:
                    pre.right = None
                    res.append(curr.val)
                    curr = curr.right
                else:
                    pre.right = curr
                    curr = curr.left
            else:
                res.append(curr.val)
                curr = curr.right
        return res
