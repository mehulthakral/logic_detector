from collections import deque
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        queue=deque()
        queue.append(root)
        if not root: return []
        result = [[root.val]]
        n1 = []
        n2 = [1]
        while queue:
            n1=[]
            for _ in range(len(n2)):
                current=queue.popleft()
                if(current.left): 
                    queue.append(current.left)
                    n1.append(current.left.val)
                if(current.right): 
                    queue.append(current.right)
                    n1.append(current.right.val)
            n2=n1
            if(len(n2)): result.append(n2)
        return result
