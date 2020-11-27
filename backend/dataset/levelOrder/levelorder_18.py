from collections import defaultdict
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if root == None:
            return []
        
        Q = [(root, 0)]
        level = defaultdict(list)
        
        while Q:
            
            node, l = Q.pop(0)
            level[l].append(node.val)
            
            if node.left:
                Q.append((node.left, l+1))
                
            if node.right:
                Q.append((node.right, l+1))
            
        
        return [*level.values()]
