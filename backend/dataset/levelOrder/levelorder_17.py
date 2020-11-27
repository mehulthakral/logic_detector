class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if(root==None):
            return []
           
        minorList = []
        ansList = []
        i = 1
        level = 0
        queue = [(root, level)]
        
        while(queue):
            node, level = queue.pop()
            if(level == i):
                ansList.append(minorList)
                minorList = []
                i += 1
            minorList.append(node.val)
            if(node.left):        
                queue.insert(0, (node.left, level+1))
            if(node.right):
                queue.insert(0, (node.right, level+1))
                
        if(minorList):
            ansList.append(minorList)
            
        return ansList
