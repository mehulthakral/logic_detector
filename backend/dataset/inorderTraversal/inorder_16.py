class Solution:
    def inorderTraversal(self, root:TreeNode)-> List[int]:
        res, stack = [], []
        n          = root
        #
        while n or stack:
            if not n: 
                # n.right was empty, backtrack one node (but avoid visiting the left branch again)
                n = stack.pop() 
            else:
                # n.right existed, reach its left-most node
                while n.left:
                    stack.append(n) 
                    n = n.left
            res.append(n.val)
            # Attempt to move right
            n = n.right
        return res
