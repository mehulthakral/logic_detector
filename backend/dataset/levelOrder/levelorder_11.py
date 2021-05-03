from dataset_server import TreeNode
from typing import List
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        q = [root]
        level = [[root.val]]
        while q:
            size = len(q)
            l = []
            while size:
                front = q.pop(0)
                size-=1

                if front.left:
                    q.append(front.left)
                    l+=[front.left.val]
                if front.right:
                    q.append(front.right)
                    l+=[front.right.val]
            if l:
                level.append(l)

        return level             
