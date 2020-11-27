from collections import deque
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        
        if not root :
            return []
        list1 = deque([root]) ; ans = []
        while list1 :
            e = list1.popleft()
            if type(e) != TreeNode :
                ans.append(e)
            else :
                if e.right : list1.appendleft(e.right)
                list1.appendleft(e.val)
                if e.left : list1.appendleft(e.left)
        return ans
