#ITERATIVE
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:        
        return_list = []
        stack = []
        node = root
        
        while True:
            
            if node is not None:
                stack.append(node)
                node = node.left
                
            elif(stack):
                node = stack.pop()
                return_list.append(node.val)
                node = node.right
            else:
                break
        return return_list