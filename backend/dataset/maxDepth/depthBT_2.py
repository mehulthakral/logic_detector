class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root != None:
            return calculate_max(root, 1)
        else:
            return 0
    

    def calculate_max(root, d):
        if root.right == None and root.left == None:
            return d
        
        d1 = d2 = 0
        
        if root.left != None:
            d1 = calculate_max(root.left, d+1)
        
        if root.right != None:
            d2 = calculate_max(root.right, d+1)
        
        return max([d1, d2])
