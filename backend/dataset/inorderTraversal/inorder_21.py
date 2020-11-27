class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # Morris Traversal
        curr = root
        output =[]
        while(curr):
            #if no left child, we can directly go the right child
            if not curr.left:
                output.append(curr.val)
                curr = curr.right
            else:
            # find the inorder predecessor of the current node
                predecessor = curr.left
                # predecessor.right = curr will occur when we have already explored the left subtree of current 
                # and reached the curr via its predecessor link and now again checking this else condition.
                # We have to break out of this loop.
                while predecessor.right !=None and predecessor.right != curr:
                    predecessor = predecessor.right # go as right as possible

                # Now check which out of 2 above condition it reached
                if predecessor.right == None:
                    # No link created till now, so create one and go to the left child of current.
                    predecessor.right = curr
                    curr = curr.left
                else:
                    # left subtree is already visited , so delete the link and then go to right subtree
                    predecessor.right = None
                    output.append(curr.val)
                    curr = curr.right
        return output 
