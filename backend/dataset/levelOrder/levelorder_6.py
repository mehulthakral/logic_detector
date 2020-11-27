class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return root
        
        queue=[]
        
        queue.append(root)
        ans=[]
        while queue:
            l=len(queue)
            level=[]
            while l!=0:
                node= queue.pop(0)
                level.append(node.val)
            
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                l=l-1
            ans.append(level)     
                
        return ans             
