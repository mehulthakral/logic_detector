class Solution:
    def inorderTraversal(self, root:TreeNode)->List[int]:
        
        stack= []
        
        res = []
        
       
        while True:
            
            if root:
                stack.append(root)
                root = root.left
            
            elif stack:
                root = stack.pop()
                res.append(root.val)
                root = root.right
                
            else:
                break
        
        return res