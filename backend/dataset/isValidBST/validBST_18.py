
class Solution:    
    def isValidBST(self, root: TreeNode) -> bool:
        mini = -2147483649
        maxi = 2147483648
        def bst(root,mini,maxi):
            if(not root):
                return True
            if(root.val<=mini or root.val>=maxi):
                return False
            return(bst(root.left,mini,root.val) and (bst(root.right,root.val,maxi)))
        return(bst(root,mini,maxi))

