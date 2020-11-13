class Solution:
   
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for x, y in prerequisites:
            graph[x].append(y)
        
        state = [UNDISCOVERED] * numCourses
        for vertex in range(numCourses):
            if not self.dfs(graph, vertex, state):
                return False
        
        return True

    def dfs(self, graph, v, state):
        stack = [(v, 0)]
        while stack:
            curr, pos = stack[-1]
            if state[curr] == PROCESSED:
                stack.pop()
                continue
            if state[curr] == DISCOVERED and pos == 0:
                return False
            if pos == 0:
                state[curr] = DISCOVERED

            for i in range(pos, len(graph[curr])):
                stack[-1] = curr, pos + 1
                stack.append((graph[curr][i], 0))
                break
            else:
                state[curr] = PROCESSED
            
        return True
