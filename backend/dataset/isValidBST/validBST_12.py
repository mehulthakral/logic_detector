class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True
        stack = [(root,float("-inf"), float("inf"))]
        while stack:
            node, mini, maxum = stack.pop()
            
            #if current node is between our min and max it satisfied the BST property
            if node.val > mini and node.val < maxum:
                #everything to the right of our current node must be greater than cur node
                if node.right:
                    stack.append((node.right,node.val, maxum))
                #everything to the left of our current node must be less than cur node
                if node.left:
                    stack.append((node.left,mini,node.val))
            else:
                return False
        return True 
