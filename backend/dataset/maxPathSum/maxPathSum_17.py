import math
class Solution:
    def helper(self,root):
        if root==None:
            return(-math.inf,-math.inf)
        l,lmax=self.helper(root.left)
        r,rmax=self.helper(root.right)
        c=max(root.val,l+root.val,r+root.val)
        s=max(c,lmax,rmax,l+r+root.val)
        return(c,s)
    def maxPathSum(self, root: TreeNode) -> int:
        return self.helper(root)[1]
