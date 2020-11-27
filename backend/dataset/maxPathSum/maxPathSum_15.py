class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if root.right==None and root.left==None:
            return root.val
        ans=[]
        def recur(node):
            if node==None:
                return 0
            left_max=0
            right_max=0
            left_max+=recur(node.left)
            right_max+=recur(node.right)
            ans.append(max(node.val+right_max,left_max+node.val,node.val+right_max+left_max,node.val))
            return max(left_max+node.val,right_max+node.val,node.val)
        recur(root)
        print(ans)
        return max(ans)
