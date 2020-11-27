class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        output, stack =[],[]
        while(stack or root):
            if root:
                # Go to the left most and push the parent into the stack
                # We need this parent node once we are done with left child and need to go to the right child
                stack.append(root)
                root = root.left
            elif stack and root == None:
                #We are done with left , so pop out the parent
                root = stack.pop()
                output.append(root.val)
                # Go to the right child
                root = root.right
        return output
