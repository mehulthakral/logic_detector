class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        ## RC ##
        ## APPROACH : RECURSION ##
        ## LOGIC : POST ORDER CALCULATION ##
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##
        
        self.max_sum = float('-inf')
        self.calculateMaxPath(root)
        return self.max_sum
        
    def calculateMaxPath(self,node):
        if(node):
            left = right = 0
            if(node.left):
                left = max(self.calculateMaxPath(node.left), 0)
            if(node.right):
                right = max(self.calculateMaxPath(node.right), 0)
            self.max_sum = max(left + right + node.val, self.max_sum)
            return max(left, right) + node.val
