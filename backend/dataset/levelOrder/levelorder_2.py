# Definition for a binary tree node.
from collections import deque
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        parent=deque() #using deque to use its feature of accesing element from left 
        
        parent.append(root)
        result=list()
        
        while parent:
            
            children=deque()
            current=[]
            temp=None
            
            while parent:#travesing through parrent level and simultaneously appending their right and left child to children deque
                temp=parent.popleft()
                current.append(temp.val)
                if temp.left:
                    children.append(temp.left)
                if temp.right:
                    children.append(temp.right)
            
            result.append(current) # appending value of all node of current level to final result for each level separately 
            parent=children # assigning children deque to parent deque for traversal through next level
                   
        return result
            
        
