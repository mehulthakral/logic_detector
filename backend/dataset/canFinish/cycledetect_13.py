from collections import *
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        child = defaultdict(set)
        parent = defaultdict(int)
        for p in prerequisites:
            child[p[1]].add(p[0])
            parent[p[0]]+=1
        
        q = deque()
        for i in range(numCourses):
            if parent[i] == 0:
                del parent[i]
                q.append(i)
        if not q:
            return False
        res = []
        while q:
            couses = q.popleft()
            res.append(couses)
            for c in child[couses]:
                parent[c] -= 1
                if parent[c] == 0:
                    del parent[c]
                    q.append(c)
                    
        return len(res) == numCourses
