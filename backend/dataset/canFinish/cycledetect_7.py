from typing import collections
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        T = []
        visited = [False]*numCourses
        queue = collections.deque()
        indegree = [0]*numCourses
        graph = collections.defaultdict(list)
        for i,j in prerequisites:
            indegree[i] += 1
            graph[j].append(i)
        n = len(graph)
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.appendleft(i)
                visited[i] = True
        while queue:
            v = queue.popleft()
            T.append(v)
            for i in graph[v]:
                if not visited[i]:
                    indegree[i] -= 1
                    if indegree[i] == 0:
                        queue.appendleft(i)
                        visited[i] = True
        return True if len(T) == numCourses else False
