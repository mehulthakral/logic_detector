class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        
        # In-order traversal: left->root->right
        
        def dfs(node):
            if not node: return
            dfs(node.left)
            ans.append(node.val)
            dfs(node.right)
            
        dfs(root)
        return ans
