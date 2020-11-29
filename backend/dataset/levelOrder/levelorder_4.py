class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        d = {}
        
        def level_order_traversal(node, k):
            if not node:
                return
            else:
                if k not in d:
                    d[k] = [node.val]
                else:
                    d[k].append(node.val)
                level_order_traversal(node.left, k + 1)
                level_order_traversal(node.right, k + 1)
                
        level_order_traversal(root, 0)
        return list(d.values())