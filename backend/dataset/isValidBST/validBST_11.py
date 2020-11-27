class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
            if not root:
                return True
            
            def DFSInOrder(node, lista):

                if node.left:
                    DFSInOrder(node.left, lista)

                lista.append(node.val)

                if node.right:
                    DFSInOrder(node.right, lista)

                return lista
            
            a = DFSInOrder(root, [])
            
            for x in range(len(a)-1):
                if a[x] == a[x+1]:
                    return False
                
            return sorted(a) == a
