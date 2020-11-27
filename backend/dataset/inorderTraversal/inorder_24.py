
#recursive
class Solution:
    def __init__(self):
        self.return_list = []
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        
        if root:
            self.inorderTraversal(root.left)
            
            self.return_list.append(root.val)
            
            self.inorderTraversal(root.right)
            
        return self.return_list
