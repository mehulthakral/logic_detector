class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        ## RC ##
        ## APPROACH : DFS ##
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##

        def helper(node):
            if(not node):   return 0
            l = r = 0
            if(node.left):
                l = max(helper(node.left), 0)
            if(node.right):
                r = max(helper(node.right), 0)
            return 1 + max(l, r)
        return helper(root)
