class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        
        ## RC ##
        ## APPROACH : STACK ##
        ## (question demands iterative solution)
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##
        
        res = []
        stack = []
        currNode = root
        
        while(currNode or stack):              # attention to condition.
            while(currNode):
                stack.append(currNode)
                currNode = currNode.left        # traverse all to the left
            
            currNode = stack.pop()
            res.append(currNode.val)            # print
            currNode = currNode.right           # traverse right
        
        return res
