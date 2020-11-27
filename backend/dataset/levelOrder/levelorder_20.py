class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        q, d, res = [(root, 1)], {}, []
        
        while q:
            node, level = q.pop(0)
            if node:
                if level in d: d[level].append(node.val)
                else: d[level] = [node.val] 
                q.append((node.left, level+1))
                q.append((node.right, level+1))
                
        for k in d:
            res.append(d[k])
                
        return res
