class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        from collections import deque
        ans = deque([])
        q= deque([])
        current = root
        
        # In-order traversal: Left->Root->Right
        while True:
            if current:  # append all the left nodes into the stack
                q.append(current)
                current = current.left
            elif q: #when reached to the far left, pop from the stack
                current = q.pop()
                ans.append(current.val) # print the left -> middle
                current = current.right  # then print the right
            else:
                break

        return list(ans)
