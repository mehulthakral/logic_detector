from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        white = defaultdict(list)
        for x,y in prerequisites:
            white[x].append(y)
        
        return not self.iscycle(white)
    
    def iscycle(self, white):
        black, grey = set(), set()
        for node in range(len(white)):
            if not self.dfs(node, black, grey, white):
                return True
        return False
    
    def dfs(self, node, black, grey, white):
        if node in black:
            return True
        if node in grey:
            return False
        grey.add(node)
        for neighbor in white[node]:
            if not self.dfs(neighbor, black, grey, white):
                return False
        black.add(node)
        grey.remove(node)
        return True
            
