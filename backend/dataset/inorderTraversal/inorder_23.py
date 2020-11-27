class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []

        while root:
            if not root.left: # if we don't have a left, this is our best in-order value at the moment. add it to the list and move right.
                res.append(root.val)
                root = root.right
            else:
                pred = self.findPredecessor(root) # find the predecessor for the given node. This is the farthest right of the first left we see.

				# if we have a right we have move on to explore this sub tree. The pred.right != root check is to ensure that we're not ex
                if pred.right != root:
                    pred.right = root
                    root = root.left
                else: 
				# otherwise, we have found a pointer back to the current root and we need to rewrite the tree structure. This is basically a form of "have we seen this before?".
                    root.left = None

        return res

    def findPredecessor(self, root: TreeNode) -> TreeNode:
        curr = root.left

        while curr.right and curr.right != root:
            curr = curr.right

        return curr

