# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        
        traversal_queue = [ root ] if root else []
        
        path = []
        
        while traversal_queue:
            
            cur_level_path, next_level_queue = [], []
            
            for node in traversal_queue:
                
                # update current level traversal path
                cur_level_path.append( node.val )
                
                if node.left:
                    next_level_queue.append( node.left )
                
                if node.right:
                    next_level_queue.append( node.right )
            
            # add current level path into path collection
            path.append( cur_level_path )
            
            # update next_level_queue as traversal_queu
            traversal_queue = next_level_queue
            
        return path
