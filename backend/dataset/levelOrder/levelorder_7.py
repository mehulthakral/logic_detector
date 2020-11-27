# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        # 横向的拆 tree 是 BFS 问题，牢记口诀 “深度优先用递归，宽度优先用deque”
        # 思路就是 把每层的 root 放进 deque 里
        # 然后每次拿到 deque 的 长度，l, 循环 l 次， 把 val 放入 temp 中，把 left,right 继续append 进入 deque 中，然后循环结束时候把每次的 temp append 进入 result 里
        # deque 空的时候 tree 就遍历尽了
        if not root: return None
        
        from collections import deque
        q = deque([root])
        result = []
        
        while q:
            l = len(q)
            temp = []
            for i in range(l):
                node = q.popleft()
                temp.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
                    
            result.append(temp)
            
        return result
                
                
                    
        
        
        
