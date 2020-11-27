
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:                        
        return Traverse(root,None,None)    

#Function to intake a node, it's max allowed node value and it's min allowed node value
def Traverse(root,min,max):
    if(root is None): 
		return True
    if((min!=None and root.val<=min.val) or (max!=None and root.val>=max.val)): 
		return False
    return Traverse(root.left, min, root) and Traverse(root.right, root, max)