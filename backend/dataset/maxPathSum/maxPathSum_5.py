fmax = lambda x,y: x if x>y else y # Custom Max Function (33% Faster than Python's Built-in Max function)
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.result = root.val
        def maxpath(node):
            if not node:
                return 0
            x = node.val
            l = fmax(0,maxpath(node.left )) # ignore "left" branch if negative
            r = fmax(0,maxpath(node.right)) # ignore "right" branch if negative
            self.result = fmax(self.result, x+l+r ) # Check if merged arc-path (left+node+right) beats the current result
            return fmax(x+l,x+r) # Try to build maximum branch value
        maxpath(root)
        return self.result
