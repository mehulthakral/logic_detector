from dataset_server import TreeNode
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:

            result = [root.val]

            def findValue(node):
                if node == None:
                    return 0
                else:
                    l = findValue(node.left)
                    r = findValue(node.right)
                    temp = max(l+node.val, r+node.val, node.val)
                    result.append(temp)
                    result.append(l+r+node.val)
                    return temp


            findValue(root)
            return max(result)
