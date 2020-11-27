class Solution:
    def get_nodes(self, root: TreeNode, level: int) -> None:
        if root:
            tmp = self.level_dict.get(level, [])
            tmp.append(root.val)
            self.level_dict[level] = tmp
            self.get_nodes(root.left, level + 1)
            self.get_nodes(root.right, level + 1)

    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        self.level_dict = dict()
        self.get_nodes(root, 0)
        return [nodes for nodes in self.level_dict.values()]
