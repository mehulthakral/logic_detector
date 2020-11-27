class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        levels = []
        
        if not root:   
            return levels
        
        q = collections.deque([root])
        
        while q: 
       
            level = []
        
            for _ in range(len(q)):
                
                node = q.popleft()
                level.append(node.val)
                
                if node.left:     
                    q.append(node.left)
                    
                if node.right:    
                    q.append(node.right)
                    
            levels.append(level)
            
        return levels
        
