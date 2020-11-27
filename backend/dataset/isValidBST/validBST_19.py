class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        valid = True
        prev = None
        
        def go(n):
            nonlocal valid, prev
            if not n:
                return
            
            go(n.left)
            if prev != None and n.val <= prev:
                valid = False
            prev = n.val
            go(n.right)
            
        go(root)
            
        return valid
