class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        ## RC ##
        ## APPROACH : RECURSION ##
        ## EDGE CASE : [10,5,15,null,null,6,20] ## (i.e all right elements must be stricly greater than root even left childs of right side, vice versa)
        
        ## LOGIC : so we to keep upper and lower limits
        ##  1. For left child, root is the upper limit
        ##  2. For right child, root is the lower limit 
        
		## TIME COMPLEXICITY : O(N) ##
		## SPACE COMPLEXICITY : O(N) ##
        
        def helper(node, lower = float('-inf'), upper = float('inf')):
            if not node:
                return True
            val = node.val
            if val <= lower or val >= upper:
                return False
            if not helper(node.right, val, upper):
                return False
            if not helper(node.left, lower, val):
                return False
            return True
        return helper(root)
