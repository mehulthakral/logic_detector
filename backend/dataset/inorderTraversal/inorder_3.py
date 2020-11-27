class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        visited = set()
        result = []
        stack = []
        if root: stack.append(root)
        
        while(len(stack) > 0):
            curr = stack.pop()
            
            if curr.left and curr.left not in visited:
                stack.append(curr)
                stack.append(curr.left)
                continue
            
            visited.add(curr)
            result.append(curr.val)
        
            if curr.right and curr.right not in visited:
                stack.append(curr.right)
        
        return result
