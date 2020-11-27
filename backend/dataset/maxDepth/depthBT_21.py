from collections import deque
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        queue=deque()
        queue.append(root)
        if(root is None): return 0
        count,n2=1,1
        while queue:
            for _ in range(n2):
                current=queue.popleft()
                if(current.left): queue.append(current.left)
                if(current.right): queue.append(current.right)
            n2=len(queue)
            if(n2!=0): count+=1
        return count
