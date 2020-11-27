class Solution:
    # O(n) time | O(n) space - because of the recursion call stack
    def isValidBST(self, root:TreeNode)->bool:
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.validater(root, float('-inf'), float('inf'))

    def validater(self, tree, minimum, maximum):

        # past leaf node/ single node tree
        if tree == None:
            return True

        # validate
        if tree.val >= maximum or tree.val <= minimum:
            return False

        # every node to the left is smaller than the one above it. the one above it is larger.
        left_handler = self.validater(
            tree.left, minimum=minimum, maximum=tree.val)

        # every node to the right is larger. the one above it is smaller.
        right_handler = self.validater(
            tree.right, minimum=tree.val, maximum=maximum)

        return left_handler and right_handler
        # return self.validater(tree.left, minimum=minimum, maximum=tree.val) and self.validater(tree.right, minimum=tree.val, maximum=maximum)
