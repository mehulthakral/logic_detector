from queue import Queue 

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        
        q = Queue()
        q.put(root)
        res = []
        while (q.qsize()):
            nextLevel = Queue()
            levelArr = []
            
            # For all nodes on the same level, add child nodes from left to right
            while (q.qsize()):
                front = q.get()
                levelArr.append(front.val)
                if front.left != None:
                    nextLevel.put(front.left)
                if front.right != None:
                    nextLevel.put(front.right)
                    
            # By this point, q has exhausted all nodes on that level
            q = nextLevel
            
            # Add the level array to the result array
            res.append(levelArr)
        
        return res
