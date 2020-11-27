class Solution:
    def maxDepth(self, root:TreeNode)->int:
        stack,level,final,counter = deque(), [], [], 0
        stack.append(root)
        if not root:
            return 0
        while len(stack)>0:
            for i in range(len(stack)):
                popped = stack.popleft()
                level.append(popped.val)
                if popped.left:
                    stack.append(popped.left)
                if popped.right:
                    stack.append(popped.right)
            final.append(level)
            counter+=1
            level = []
        return counter

                
        
