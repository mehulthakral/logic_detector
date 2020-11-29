
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:                        
        return self.Traverse(root,None,None)    

    #Function to intake a node, it's max allowed node value and it's min allowed node value
    def Traverse(self,root,min,max):
        if(root is None): 
          return True
        if((min!=None and root.val<=min.val) or (max!=None and root.val>=max.val)): 
          return False
        return self.Traverse(root.left, min, root) and self.Traverse(root.right, root, max)