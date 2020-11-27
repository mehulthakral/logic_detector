class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root :
            return True
        def inorder(root) :
            if root.left :
                inorder(root.left)
            ans.append(root.val)
            if root.right :
                inorder(root.right)
        ans=[]
        inorder(root)
        if sorted(ans)==ans and len(set(ans))==len(ans) :
            return True
        return False
