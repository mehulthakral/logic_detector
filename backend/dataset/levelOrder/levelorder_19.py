class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        self._levels = []
        self.get_level(root, 0)
        return self._levels
            
    def get_level(self, root, depth):
        if(not root):
            return
        if(depth == len(self._levels)):
            self._levels.append([])
        self._levels[depth].append(root.val)
        self.get_level(root.left, depth + 1)
        self.get_level(root.right, depth + 1)
